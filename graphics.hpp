#pragma once
#include "object_handle.hpp"
#include "id_buffer.hpp"

namespace boba
{
  Vector3 ScreenToViewSpace(const Matrix& proj, u32 x, u32 y);

  class Shader;
  class Material;

  enum FileEvent;

  enum class ShaderType
  {
    VertexShader,
    PixelShader,
    GeometryShader,
    ComputeShader,
  };

  struct BufferFlag
  {
    enum Enum
    {
      CreateMipMaps        = 1 << 0,
      CreateDepthBuffer    = 1 << 1,
      CreateSrv            = 1 << 2,
      CreateUav            = 1 << 3,
    };

    struct Bits
    {
      u32 mipMaps : 1;
      u32 depthBuffer : 1;
      u32 srv : 1;
      u32 uav : 1;
    };
  };

  typedef Flags<BufferFlag> BufferFlags;

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
      bool CreateBackBuffers(u32 width, u32 height, DXGI_FORMAT format);
      void Present();

      string _name;
      HWND _hwnd;
      CComPtr<IDXGISwapChain> _swapChain;
      DXGI_SWAP_CHAIN_DESC _desc;
      ObjectHandle _renderTarget;
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

    ObjectHandle LoadTexture(
        const char* filename,
        const char* friendlyName = nullptr,
        bool srgb = false,
        D3DX11_IMAGE_INFO* info = nullptr);

    ObjectHandle LoadTextureFromMemory(
        const void* buf,
        u32 len,
        const char* friendlyName = nullptr,
        bool srgb = false,
        D3DX11_IMAGE_INFO* info = nullptr);

    const Setup& CurSetup() const { return _curSetup; }

    const char *vs_profile() const { return _vsProfile; }
    const char *ps_profile() const { return _psProfile; }
    const char *cs_profile() const { return _csProfile; }
    const char *gs_profile() const { return _gsProfile; }

    void GetPredefinedGeometry(
        PredefinedGeometry geom,
        ObjectHandle *vb,
        int *vertex_size,
        ObjectHandle *ib,
        DXGI_FORMAT *index_format,
        int *index_count);

    ObjectHandle CreateInputLayout(
        const vector<D3D11_INPUT_ELEMENT_DESC> &desc,
        const vector<char> &shader_bytecode);

    ObjectHandle CreateBuffer(
        D3D11_BIND_FLAG bind,
        int size,
        bool dynamic,
        const void* buf = nullptr,
        int userData = 0);

    ObjectHandle CreateVertexShader(const vector<char> &shader_bytecode, const string& id);
    ObjectHandle CreatePixelShader(const vector<char> &shader_bytecode, const string& id);
    ObjectHandle CreateComputeShader(const vector<char> &shader_bytecode, const string &id);
    ObjectHandle CreateGeometryShader(const vector<char> &shader_bytecode, const string &id);

    ObjectHandle CreateRasterizerState(const D3D11_RASTERIZER_DESC &desc, const char *name = nullptr);
    ObjectHandle CreateBlendState(const D3D11_BLEND_DESC &desc, const char *name = nullptr);
    ObjectHandle CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC &desc, const char *name = nullptr);
    ObjectHandle CreateSamplerState(const D3D11_SAMPLER_DESC &desc, const char *name = nullptr);
    ObjectHandle CreateSwapChain(
        const TCHAR* name,
        u32 width,
        u32 height,
        DXGI_FORMAT format,
        WNDPROC wndProc,
        HINSTANCE instance);
    ObjectHandle RenderTargetForSwapChain(ObjectHandle h);

    D3D_FEATURE_LEVEL FeatureLevel() const { return _featureLevel; }

    bool GetTextureSize(ObjectHandle h, u32* x, u32* y);
    ObjectHandle GetTempRenderTarget(
        int width,
        int height,
        DXGI_FORMAT format,
        const BufferFlags& bufferFlags);

    void ReleaseTempRenderTarget(ObjectHandle h);

    ObjectHandle CreateRenderTarget(
        int width,
        int height,
        DXGI_FORMAT format,
        const BufferFlags& bufferFlags,
        const string& name = "");

    ObjectHandle CreateStructuredBuffer(int elemSize, int numElems, bool createSrv);
    ObjectHandle CreateTexture(const D3D11_TEXTURE2D_DESC &desc, const char *name);
    ObjectHandle GetTexture(const char *filename);

    bool ReadTexture(const char *filename, D3DX11_IMAGE_INFO *info, u32 *pitch, vector<u8> *bits);

    // Create a texture, and fill it with data
    bool CreateTexture(int width, int height, DXGI_FORMAT fmt, void *data, int data_width, int data_height, int data_pitch, TextureResource *out);
    ObjectHandle CreateTexture(int width, int height, DXGI_FORMAT fmt, void *data, int data_width, int data_height, int data_pitch, const char *friendlyName);

    SwapChain* GetSwapChain(ObjectHandle h);

    ObjectHandle FindTechnique(const string &name);
    ObjectHandle FindResource(const string &name);
    ObjectHandle FindSampler(const string &name);
    ObjectHandle FindBlendState(const string &name);
    ObjectHandle FindRasterizerState(const string &name);
    ObjectHandle FindDepthStencilState(const string &name);

    ObjectHandle DefaultRasterizerState() const { return _defaultRasterizerState; }
    ObjectHandle DefaultDepthStencilState() const { return _defaultDepthStencilState; }
    uint32_t DefaultStencilRef() const { return 0; }
    ObjectHandle  DefaultBlendState() const { return _defaultBlendState; }
    const float *DefaultBlendFactors() const { return _defaultBlendFactors; }
    uint32_t DefaultSampleMask() const { return 0xffffffff; }

    DeferredContext *CreateDeferredContext(bool canUseImmediate);
    void DestroyDeferredContext(DeferredContext *ctx);
    void AddCommandList(ID3D11CommandList *cmd_list);

    bool VSync() const { return _vsync; }
    void SetVSync(bool value) { _vsync = value; }

    static ObjectHandle MakeObjectHandle(ObjectHandle::Type type, int idx, int data = 0);

    void SetDisplayAllModes(bool value) { _displayAllModes = value; }
    bool DisplayAllModes() const { return _displayAllModes; }

    const DXGI_MODE_DESC &selectedDisplayMode() const;

    ID3D11Device* Device() { return _device.p; }

    void CreateDefaultSwapChain(
        u32 width,
        u32 height,
        DXGI_FORMAT format,
        WNDPROC wndProc,
        HINSTANCE instance);

    void ClearRenderTarget(ObjectHandle h);
    void Present();
    
    void GetBackBufferSize(int* width, int* height);
    ObjectHandle DefaultSwapChain();

    bool LoadShadersFromFile(
        const string& filenameBase,
        ObjectHandle* vs,
        ObjectHandle* ps,
        ObjectHandle* inputLayout,
        u32 vertexFlags,
        const char* vsEntry = "VsMain",
        const char* psEntry = "PsMain");

    bool LoadComputeShadersFromFile(
        const string& filenameBase,
        ObjectHandle* shader,
        const char* entry = "CsMain");

    void AddText(const char* text, const char* font, float size, float x, float y, u32 color);
    void AddText(const wchar_t* text, const char* font, float size, float x, float y, u32 color);

  private:

    bool CreateDevice();

    bool Init(HINSTANCE hInstance);

    bool CreateBufferInner(D3D11_BIND_FLAG bind, int size, bool dynamic, const void* data, ID3D11Buffer** buffer);

    bool CreateRenderTarget(
        int width,
        int height,
        DXGI_FORMAT format,
        const BufferFlags& bufferFlags,
        RenderTargetResource *out);
    bool CreateTexture(const D3D11_TEXTURE2D_DESC &desc, TextureResource *out);

    bool CreateDefaultGeometry();

    ID3D11ShaderResourceView* GetShaderResourceView(ObjectHandle h);

    // given texture data and a name, insert it into the GOH chain
    ObjectHandle InsertTexture(TextureResource *data, const char *friendlyName);

    static INT_PTR CALLBACK dialogWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    static bool EnumerateDisplayModes(HWND hWnd);

#if WITH_FONT_RENDERING 
    struct TextElement
    {
      TextElement(const wstring& str, IFW1FontWrapper* font, float size, float x, float y, u32 color)
          : str(str)
          , font(font)
          , size(size)
          , x(x)
          , y(y)
          , color(color)
      {
      }

      wstring str;
      IFW1FontWrapper* font;
      float size;
      float x, y;
      u32 color;
    };
#endif
    Setup _curSetup;

    CComPtr<ID3D11Device> _device;

    CComPtr<ID3D11DeviceContext> _immediateContext;

#if WITH_DXGI_DEBUG
    CComPtr<ID3D11Debug> _d3dDebug;
#endif

    // resources
    enum { IdCount = 1 << ObjectHandle::cIdBits };
    IdBuffer<ID3D11VertexShader*, IdCount> _vertexShaders;
    IdBuffer<ID3D11PixelShader*, IdCount> _pixelShaders;
    IdBuffer<ID3D11ComputeShader*, IdCount> _computeShaders;
    IdBuffer<ID3D11GeometryShader*, IdCount> _geometryShaders;
    IdBuffer<ID3D11InputLayout*, IdCount> _inputLayouts;
    IdBuffer<ID3D11Buffer*, IdCount> _vertexBuffers;
    IdBuffer<ID3D11Buffer*, IdCount> _indexBuffers;
    IdBuffer<ID3D11Buffer*, IdCount> _constantBuffers;

    IdBuffer<ID3D11BlendState*, IdCount> _blendStates;
    IdBuffer<ID3D11DepthStencilState*, IdCount> _depthStencilStates;
    IdBuffer<ID3D11RasterizerState*, IdCount> _rasterizerStates;
    IdBuffer<ID3D11SamplerState*, IdCount> _sampler_states;

    IdBuffer<TextureResource*, IdCount> _textures;
    IdBuffer<RenderTargetResource*, IdCount> _renderTargets;
    IdBuffer<SimpleResource*, IdCount> _resources;
    IdBuffer<ID3D11ShaderResourceView*, IdCount> _shaderResourceViews;
    IdBuffer<StructuredBuffer*, IdCount> _structuredBuffers;
    IdBuffer<SwapChain*, 16> _swapChains;

    static Graphics* _instance;
    static IDXGIDebug* _debugInterface;
    static HMODULE _debugModule;

    D3D_FEATURE_LEVEL _featureLevel;

    ObjectHandle _defaultRenderTarget;
    ObjectHandle _dummyTexture;

    ObjectHandle _defaultRasterizerState;
    ObjectHandle _defaultDepthStencilState;
    CComPtr<ID3D11SamplerState> _defaultSamplerState;
    float _defaultBlendFactors[4];
    ObjectHandle _defaultBlendState;

    const char *_vsProfile;
    const char *_psProfile;
    const char *_csProfile;
    const char *_gsProfile;

    bool _vsync;
    int _totalBytesAllocated;

    map<PredefinedGeometry, pair<ObjectHandle, ObjectHandle> > _predefinedGeometry;

    ObjectHandle _swapChain;

    HWND _hwnd;
    HINSTANCE _hInstance;
    bool _displayAllModes;

#if WITH_FONT_RENDERING
    CComPtr<IFW1Factory> _fw1Factory;
    CComPtr<IFW1FontWrapper> _fw1FontWrapper;
    vector<TextElement> _textElements;
#endif

  };

#define GRAPHICS Graphics::Instance()

#define GFX_CreateBuffer(bind, size, dynamic, buf, data) GRAPHICS.CreateBuffer(bind, size, dynamic, buf, data);

  struct ScopedRenderTarget
  {
    ScopedRenderTarget(int width, int height, DXGI_FORMAT format, const BufferFlags& bufferFlags)
    {
      h = GRAPHICS.GetTempRenderTarget(width, height, format, bufferFlags);
    }

    ~ScopedRenderTarget()
    {
      if (h.IsValid())
      {
        GRAPHICS.ReleaseTempRenderTarget(h);
      }
    }

    ObjectHandle h;
  };


}
