#pragma once


//#include "utils.hpp"
//#include "id_buffer.hpp"
#include "graphics_object_handle.hpp"
#include "id_buffer.hpp"
//#include "technique.hpp"

namespace boba
{
  class Shader;
  class Material;

  enum FileEvent;

  class Graphics
  {
    friend class DeferredContext;
    friend class PackedResourceManager;
    friend class ResourceManager;
  public:

    struct VideoAdapter
    {
      CComPtr<IDXGIAdapter> adapter;
      DXGI_ADAPTER_DESC desc;
      vector<DXGI_MODE_DESC> displayModes;
    };

    struct Setup
    {
      Setup() : selectedAdapter(-1), selectedDisplayMode(-1), multisampleCount(-1), selectedAspectRatio(-1), windowed(false) {}

      CComPtr<IDXGIFactory> dxgi_factory;
      vector<VideoAdapter> videoAdapters;
      int selectedAdapter;
      int selectedDisplayMode;
      int selectedAspectRatio;
      int multisampleCount;
      bool windowed;
      int width, height;
    };

    enum BufferFlags
    {
      kCreateMipMaps        = 1 << 0,
      kCreateDepthBuffer    = 1 << 1,
      kCreateSrv            = 1 << 2,
      kCreateUav            = 1 << 3,
    };

    enum PredefinedGeometry
    {
      kGeomFsQuadPos,
      kGeomFsQuadPosTex,
    };

    template<class Resource, class Desc>
    struct ResourceAndDesc
    {
      void release() {
        resource.Release();
      }
      CComPtr<Resource> resource;
      Desc desc;
    };

    struct RenderTargetResource
    {
      RenderTargetResource() : in_use(true) {
        reset();
      }

      void reset() {
        texture.release();
        depth_stencil.release();
        rtv.release();
        dsv.release();
        srv.release();
        uav.release();
      }

      bool in_use;
      ResourceAndDesc<ID3D11Texture2D, D3D11_TEXTURE2D_DESC> texture;
      ResourceAndDesc<ID3D11Texture2D, D3D11_TEXTURE2D_DESC> depth_stencil;
      ResourceAndDesc<ID3D11RenderTargetView, D3D11_RENDER_TARGET_VIEW_DESC> rtv;
      ResourceAndDesc<ID3D11DepthStencilView, D3D11_DEPTH_STENCIL_VIEW_DESC> dsv;
      ResourceAndDesc<ID3D11ShaderResourceView, D3D11_SHADER_RESOURCE_VIEW_DESC> srv;
      ResourceAndDesc<ID3D11UnorderedAccessView, D3D11_UNORDERED_ACCESS_VIEW_DESC> uav;
    };

    struct TextureResource
    {
      void reset() {
        texture.release();
        view.release();
      }
      ResourceAndDesc<ID3D11Texture2D, D3D11_TEXTURE2D_DESC> texture;
      ResourceAndDesc<ID3D11ShaderResourceView, D3D11_SHADER_RESOURCE_VIEW_DESC> view;
    };

    struct SimpleResource
    {
      void reset() {
        resource.Release();
        view.release();
      }
      CComPtr<ID3D11Resource> resource;
      ResourceAndDesc<ID3D11ShaderResourceView, D3D11_SHADER_RESOURCE_VIEW_DESC> view;
    };

    struct StructuredBuffer
    {
      ResourceAndDesc<ID3D11Buffer, D3D11_BUFFER_DESC> buffer;
      ResourceAndDesc<ID3D11ShaderResourceView, D3D11_SHADER_RESOURCE_VIEW_DESC> srv;
      ResourceAndDesc<ID3D11UnorderedAccessView, D3D11_UNORDERED_ACCESS_VIEW_DESC> uav;
    };

    struct SwapChain
    {
      SwapChain(const char* name) : _name(name) {}
      bool CreateBackBuffers(size_t width, size_t height, DXGI_FORMAT format);
      void Present();

      string _name;
      HWND _hwnd;
      CComPtr<IDXGISwapChain> _swapChain;
      DXGI_SWAP_CHAIN_DESC _desc;
      GraphicsObjectHandle _renderTarget;
      CD3D11_VIEWPORT _viewport;
    };

    Graphics();
    ~Graphics();

    static bool Create(HINSTANCE hInstance);
    static bool Destroy();

    inline static Graphics& Instance()
    {
      return *_instance;
    }


    const Setup& CurSetup() const { return _curSetup; }

    const char *vs_profile() const { return _vs_profile; }
    const char *ps_profile() const { return _ps_profile; }
    const char *cs_profile() const { return _cs_profile; }
    const char *gs_profile() const { return _gs_profile; }

    void GetPredefinedGeometry(PredefinedGeometry geom, GraphicsObjectHandle *vb, int *vertex_size, GraphicsObjectHandle *ib, DXGI_FORMAT *index_format, int *index_count);

    GraphicsObjectHandle CreateInputLayout(const vector<D3D11_INPUT_ELEMENT_DESC> &desc, const vector<char> &shader_bytecode);

    GraphicsObjectHandle CreateBuffer(D3D11_BIND_FLAG bind, int size, bool dynamic, const void* buf, int data);

    GraphicsObjectHandle CreateVertexShader(const vector<char> &shader_bytecode, const string   &id);
    GraphicsObjectHandle CreatePixelShader(const vector<char> &shader_bytecode, const string &id);
    GraphicsObjectHandle CreateComputeShader(const vector<char> &shader_bytecode, const string &id);
    GraphicsObjectHandle CreateGeometryShader(const vector<char> &shader_bytecode, const string &id);

    GraphicsObjectHandle CreateRasterizerState(const D3D11_RASTERIZER_DESC &desc, const char *name = nullptr);
    GraphicsObjectHandle CreateBlendState(const D3D11_BLEND_DESC &desc, const char *name = nullptr);
    GraphicsObjectHandle CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC &desc, const char *name = nullptr);
    GraphicsObjectHandle CreateSamplerState(const D3D11_SAMPLER_DESC &desc, const char *name = nullptr);
    GraphicsObjectHandle CreateSwapChain(
        const char* name,
        size_t width,
        size_t height,
        DXGI_FORMAT format,
        WNDPROC wndProc,
        HINSTANCE instance);

    D3D_FEATURE_LEVEL FeatureLevel() const { return _feature_level; }

    GraphicsObjectHandle GetTempRenderTarget(
        DeferredContext* ctx,
        int width,
        int height,
        DXGI_FORMAT format,
        u32 bufferFlags,
        const string &name);
    void ReleaseTempRenderTarget(GraphicsObjectHandle h);

    GraphicsObjectHandle CreateRenderTarget(
        DeferredContext* ctx,
        int width,
        int height,
        DXGI_FORMAT format,
        u32 bufferFlags,
        const string &name);

    GraphicsObjectHandle CreateStructuredBuffer(int elemSize, int numElems, bool createSrv);
    GraphicsObjectHandle CreateTexture(const D3D11_TEXTURE2D_DESC &desc, const char *name);
    GraphicsObjectHandle GetTexture(const char *filename);

    bool ReadTexture(const char *filename, D3DX11_IMAGE_INFO *info, u32 *pitch, vector<u8> *bits);

    // Create a texture, and fill it with data
    bool CreateTexture(int width, int height, DXGI_FORMAT fmt, void *data, int data_width, int data_height, int data_pitch, TextureResource *out);
    GraphicsObjectHandle CreateTexture(int width, int height, DXGI_FORMAT fmt, void *data, int data_width, int data_height, int data_pitch, const char *friendly_name);

    bool LoadTechniques(const string& filename);
    //Technique *GetTechnique(GraphicsObjectHandle h);
    SwapChain* GetSwapChain(GraphicsObjectHandle h);

    GraphicsObjectHandle FindTechnique(const string &name);
    GraphicsObjectHandle FindResource(const string &name);
    GraphicsObjectHandle FindSampler(const string &name);
    GraphicsObjectHandle FindBlendState(const string &name);
    GraphicsObjectHandle FindRasterizerState(const string &name);
    GraphicsObjectHandle FindDepthStencilState(const string &name);

    GraphicsObjectHandle default_rasterizer_state() const { return _default_rasterizer_state; }
    GraphicsObjectHandle default_depth_stencil_state() const { return _default_depth_stencil_state; }
    uint32_t default_stencil_ref() const { return 0; }
    GraphicsObjectHandle  default_blend_state() const { return _default_blend_state; }
    const float *default_blend_factors() const { return _default_blend_factors; }
    uint32_t default_sample_mask() const { return 0xffffffff; }

    DeferredContext *CreateDeferredContext(bool canUseImmediate);
    void DestroyDeferredContext(DeferredContext *ctx);
    void AddCommandList(ID3D11CommandList *cmd_list);

    bool vsync() const { return _vsync; }
    void set_vsync(bool value) { _vsync = value; }

    static GraphicsObjectHandle MakeObjectHandle(GraphicsObjectHandle::Type type, int idx, int data = 0);

    void setDisplayAllModes(bool value) { _displayAllModes = value; }
    bool displayAllModes() const { return _displayAllModes; }

    const DXGI_MODE_DESC &selectedDisplayMode() const;

    ID3D11Device* Device() { return _device.p; }

  private:

    bool CreateDevice();

    bool Init(HINSTANCE hInstance);

    bool CreateBufferInner(D3D11_BIND_FLAG bind, int size, bool dynamic, const void* data, ID3D11Buffer** buffer);

    bool CreateRenderTarget(
        DeferredContext* ctx,
        int width,
        int height,
        DXGI_FORMAT format,
        u32 bufferFlags,
        RenderTargetResource *out);
    bool CreateTexture(const D3D11_TEXTURE2D_DESC &desc, TextureResource *out);

    bool CreateDefaultGeometry();

    bool TechniqueFileChanged(const char *filename, void *token);
    bool ShaderFileChanged(const char *filename, void *token);

    // given texture data and a name, insert it into the GOH chain
    GraphicsObjectHandle InsertTexture(TextureResource *data, const char *friendly_name);

    //void FillSystemResourceViews(const ResourceViewArray &props, TextureArray *out) const;

    GraphicsObjectHandle LoadTexture(const char *filename, const char *friendly_name, bool srgb, D3DX11_IMAGE_INFO *info);
    GraphicsObjectHandle LoadTextureFromMemory(const void *buf, size_t len, const char *friendly_name, bool srgb, D3DX11_IMAGE_INFO *info);


    static INT_PTR CALLBACK dialogWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    static bool EnumerateDisplayModes(HWND hWnd);

    Setup _curSetup;

    CComPtr<ID3D11Device> _device;

    CComPtr<ID3D11DeviceContext> _immediate_context;

#ifdef _DEBUG
    CComPtr<ID3D11Debug> _d3d_debug;
#endif

    // resources
    enum { IdCount = 1 << GraphicsObjectHandle::cIdBits };
    IdBuffer<ID3D11VertexShader *, IdCount> _vertex_shaders;
    IdBuffer<ID3D11PixelShader *, IdCount> _pixel_shaders;
    IdBuffer<ID3D11ComputeShader *, IdCount> _compute_shaders;
    IdBuffer<ID3D11GeometryShader *, IdCount> _geometry_shaders;
    IdBuffer<ID3D11InputLayout *, IdCount> _input_layouts;
    IdBuffer<ID3D11Buffer *, IdCount> _vertex_buffers;
    IdBuffer<ID3D11Buffer *, IdCount> _index_buffers;
    IdBuffer<ID3D11Buffer *, IdCount> _constant_buffers;
    //IdBuffer<Technique *, IdCount> _techniques;

    IdBuffer<ID3D11BlendState *, IdCount> _blend_states;
    IdBuffer<ID3D11DepthStencilState *, IdCount> _depth_stencil_states;
    IdBuffer<ID3D11RasterizerState *, IdCount> _rasterizer_states;
    IdBuffer<ID3D11SamplerState *, IdCount> _sampler_states;

    IdBuffer<TextureResource *, IdCount> _textures;
    IdBuffer<RenderTargetResource *, IdCount> _render_targets;
    IdBuffer<SimpleResource *, IdCount> _resources;
    IdBuffer<ID3D11ShaderResourceView *, IdCount> _shader_resource_views;
    IdBuffer<StructuredBuffer *, IdCount> _structured_buffers;
    IdBuffer<SwapChain*, 16> _swapChains;

    static Graphics* _instance;
    static IDXGIDebug* _debugInterface;
    static HMODULE _debugModule;

    D3D_FEATURE_LEVEL _feature_level;

    GraphicsObjectHandle _default_render_target;
    GraphicsObjectHandle _dummy_texture;

    GraphicsObjectHandle _default_rasterizer_state;
    GraphicsObjectHandle _default_depth_stencil_state;
    CComPtr<ID3D11SamplerState> _default_sampler_state;
    float _default_blend_factors[4];
    GraphicsObjectHandle _default_blend_state;

    const char *_vs_profile;
    const char *_ps_profile;
    const char *_cs_profile;
    const char *_gs_profile;

    bool _vsync;
    int _totalBytesAllocated;

    map<PredefinedGeometry, pair<GraphicsObjectHandle, GraphicsObjectHandle> > _predefined_geometry;

    HWND _hwnd;
    HINSTANCE _hInstance;
    bool _displayAllModes;
  };

#define GRAPHICS Graphics::Instance()

#define GFX_CreateBuffer(bind, size, dynamic, buf, data) GRAPHICS.CreateBuffer(bind, size, dynamic, buf, data);

}
