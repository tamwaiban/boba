#pragma once

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable: 4244 4267)
#endif

#include "common.pb.h"
#include "editor_settings.pb.h"
#include "effect_settings.pb.h"
#include "effect_settings_plexus.pb.h"
#include "editor_styles.pb.h"

#ifdef _WIN32
#pragma warning(pop)
#endif

namespace editor
{
  struct Vector2;
  struct Vector3;
  struct Vector4;
  struct FloatKeyframe;
  struct FloatAnim;
  struct Vector3Keyframe;
  struct Vector3Anim;
  struct Settings;
  struct StyleSetting;
  struct StyleSettings;
  struct EffectSetting;
  struct EffectSettings;
  struct Plexus;
  struct TextPath;
  struct Displacement;
  struct NoiseEffector;

  FloatKeyframe FromProtocol(const common::protocol::FloatKeyframe& p);
  void ToProtocol(const FloatKeyframe& v, common::protocol::FloatKeyframe* p);
  FloatAnim FromProtocol(const common::protocol::FloatAnim& p);
  void ToProtocol(const FloatAnim& v, common::protocol::FloatAnim* p);
  Vector3Keyframe FromProtocol(const common::protocol::Vector3Keyframe& p);
  void ToProtocol(const Vector3Keyframe& v, common::protocol::Vector3Keyframe* p);
  Vector3Anim FromProtocol(const common::protocol::Vector3Anim& p);
  void ToProtocol(const Vector3Anim& v, common::protocol::Vector3Anim* p);
  Settings FromProtocol(const editor::protocol::Settings& p);
  void ToProtocol(const Settings& v, editor::protocol::Settings* p);
  StyleSetting FromProtocol(const editor::protocol::StyleSetting& p);
  void ToProtocol(const StyleSetting& v, editor::protocol::StyleSetting* p);
  StyleSettings FromProtocol(const editor::protocol::StyleSettings& p);
  void ToProtocol(const StyleSettings& v, editor::protocol::StyleSettings* p);
  EffectSetting FromProtocol(const effect::protocol::EffectSetting& p);
  void ToProtocol(const EffectSetting& v, effect::protocol::EffectSetting* p);
  EffectSettings FromProtocol(const effect::protocol::EffectSettings& p);
  void ToProtocol(const EffectSettings& v, effect::protocol::EffectSettings* p);
  Plexus FromProtocol(const effect::protocol::plexus::Plexus& p);
  void ToProtocol(const Plexus& v, effect::protocol::plexus::Plexus* p);
  TextPath FromProtocol(const effect::protocol::plexus::TextPath& p);
  void ToProtocol(const TextPath& v, effect::protocol::plexus::TextPath* p);
  Displacement FromProtocol(const effect::protocol::plexus::Displacement& p);
  void ToProtocol(const Displacement& v, effect::protocol::plexus::Displacement* p);
  NoiseEffector FromProtocol(const effect::protocol::plexus::NoiseEffector& p);
  void ToProtocol(const NoiseEffector& v, effect::protocol::plexus::NoiseEffector* p);
  
  template<typename T, typename U>
  vector<T> FromProtocolRepeated(const google::protobuf::RepeatedPtrField<U>& v)
  {
    vector<T> res;
    for (const auto& x : v)
    {
      res.push_back(FromProtocol(x));
    }
    return res;
  }
  
  struct FloatKeyframe
  {
    uint32_t time;
    float value;
  };
  struct FloatAnim
  {
    uint32_t type;
    vector<FloatKeyframe> keyframe;
  };
  struct Vector3Keyframe
  {
    uint32_t time;
    Vector3f value;
  };
  struct Vector3Anim
  {
    uint32_t type;
    vector<Vector3Keyframe> keyframe;
  };
  struct Settings
  {
    uint32_t tickerHeight;
    uint32_t tickerInterval;
    uint32_t ticksPerInterval;
    uint32_t effectViewWidth;
    uint32_t effectRowHeight;
    uint32_t statusBarHeight;
    uint32_t effectHeight;
    uint32_t resizeHandle;
    uint32_t timelineZoomMin;
    uint32_t timelineZoomMax;
    uint32_t timelineZoomDefault;
    uint32_t keyframeSize;
    Color defaultRowColor;
    Color selectedRowColor;
    Color hoverRowColor;
    Color invalidHoverRowColor;
    Color defaultLineColor;
    Color effectViewBackgroundColor;
    Color effectViewBackgroundColorSelected;
    Color timelineViewBackgroundColor;
    Color effectLineColor;
    Color keyframeDefaultColor;
    Color keyframeSelectedColor;
    Color varTextColor;
    Color varValueColor;
    Color effectIconExpandedColor;
    Color effectIconCollapsedColor;
  };
  struct StyleSetting
  {
    string id;
    Color fillColor;
    Color outlineColor;
    float outlineThickness;
    uint32_t fontStyle;
  };
  struct StyleSettings
  {
    vector<StyleSetting> styleSetting;
  };
  struct EffectSetting
  {
    enum class Type
    {
      Unknown = 0,
      Plexus = 1,
    };

    EffectSetting::Type type;
    string effectClass;
    uint32_t id;
    string name;
    uint32_t startTime;
    uint32_t endTime;
    std::vector<uint8_t> configMsg;
    string configFile;
  };
  struct EffectSettings
  {
    vector<EffectSetting> effectSetting;
    string soundtrack;
  };
  struct Plexus
  {
    vector<TextPath> textPaths;
    vector<NoiseEffector> noiseEffectors;
  };
  struct TextPath
  {
    string text;
  };
  struct Displacement
  {
    FloatAnim x;
    FloatAnim y;
    FloatAnim z;
  };
  struct NoiseEffector
  {
    enum class ApplyTo
    {
      Position = 1,
      Scale = 2,
    };

    NoiseEffector::ApplyTo applyTo;
    Displacement displacement;
  };
  

  inline Color FromProtocol(const common::protocol::Color4& col)
  {
    return Color(col.r(), col.g(), col.b(), col.a());
  }

  inline void ToProtocol(const Color& v, common::protocol::Color4* p)
  {
    p->set_r(v.r);
    p->set_g(v.g);
    p->set_b(v.b);
    p->set_a(v.a);
  }

  inline Vector3f FromProtocol(const common::protocol::Vector3& v)
  {
    return Vector3f(v.x(), v.y(), v.z());
  }

  inline void ToProtocol(const Vector3f& v, common::protocol::Vector3* p)
  {
    p->set_x(v.x);
    p->set_y(v.y);
    p->set_z(v.z);
  }


  inline FloatKeyframe FromProtocol(const common::protocol::FloatKeyframe& p)
  {
    FloatKeyframe res;
    res.time = p.time();
    res.value = p.value();
    return res;
  }

  inline void ToProtocol(const FloatKeyframe& v, common::protocol::FloatKeyframe* p)
  {
    p->set_time(v.time);
    p->set_value(v.value);
  }


  inline FloatAnim FromProtocol(const common::protocol::FloatAnim& p)
  {
    FloatAnim res;
    res.type = p.type();
    res.keyframe = FromProtocolRepeated<FloatKeyframe>(p.keyframe());
    return res;
  }

  inline void ToProtocol(const FloatAnim& v, common::protocol::FloatAnim* p)
  {
    p->set_type(v.type);
    for (const auto& x : v.keyframe)
      ToProtocol(x, p->add_keyframe());
  }


  inline Vector3Keyframe FromProtocol(const common::protocol::Vector3Keyframe& p)
  {
    Vector3Keyframe res;
    res.time = p.time();
    res.value = FromProtocol(p.value());
    return res;
  }

  inline void ToProtocol(const Vector3Keyframe& v, common::protocol::Vector3Keyframe* p)
  {
    p->set_time(v.time);
    ToProtocol(v.value, p->mutable_value());
  }


  inline Vector3Anim FromProtocol(const common::protocol::Vector3Anim& p)
  {
    Vector3Anim res;
    res.type = p.type();
    res.keyframe = FromProtocolRepeated<Vector3Keyframe>(p.keyframe());
    return res;
  }

  inline void ToProtocol(const Vector3Anim& v, common::protocol::Vector3Anim* p)
  {
    p->set_type(v.type);
    for (const auto& x : v.keyframe)
      ToProtocol(x, p->add_keyframe());
  }


  inline Settings FromProtocol(const editor::protocol::Settings& p)
  {
    Settings res;
    res.tickerHeight = p.ticker_height();
    res.tickerInterval = p.ticker_interval();
    res.ticksPerInterval = p.ticks_per_interval();
    res.effectViewWidth = p.effect_view_width();
    res.effectRowHeight = p.effect_row_height();
    res.statusBarHeight = p.status_bar_height();
    res.effectHeight = p.effect_height();
    res.resizeHandle = p.resize_handle();
    res.timelineZoomMin = p.timeline_zoom_min();
    res.timelineZoomMax = p.timeline_zoom_max();
    res.timelineZoomDefault = p.timeline_zoom_default();
    res.keyframeSize = p.keyframe_size();
    res.defaultRowColor = FromProtocol(p.default_row_color());
    res.selectedRowColor = FromProtocol(p.selected_row_color());
    res.hoverRowColor = FromProtocol(p.hover_row_color());
    res.invalidHoverRowColor = FromProtocol(p.invalid_hover_row_color());
    res.defaultLineColor = FromProtocol(p.default_line_color());
    res.effectViewBackgroundColor = FromProtocol(p.effect_view_background_color());
    res.effectViewBackgroundColorSelected = FromProtocol(p.effect_view_background_color_selected());
    res.timelineViewBackgroundColor = FromProtocol(p.timeline_view_background_color());
    res.effectLineColor = FromProtocol(p.effect_line_color());
    res.keyframeDefaultColor = FromProtocol(p.keyframe_default_color());
    res.keyframeSelectedColor = FromProtocol(p.keyframe_selected_color());
    res.varTextColor = FromProtocol(p.var_text_color());
    res.varValueColor = FromProtocol(p.var_value_color());
    res.effectIconExpandedColor = FromProtocol(p.effect_icon_expanded_color());
    res.effectIconCollapsedColor = FromProtocol(p.effect_icon_collapsed_color());
    return res;
  }

  inline void ToProtocol(const Settings& v, editor::protocol::Settings* p)
  {
    p->set_ticker_height(v.tickerHeight);
    p->set_ticker_interval(v.tickerInterval);
    p->set_ticks_per_interval(v.ticksPerInterval);
    p->set_effect_view_width(v.effectViewWidth);
    p->set_effect_row_height(v.effectRowHeight);
    p->set_status_bar_height(v.statusBarHeight);
    p->set_effect_height(v.effectHeight);
    p->set_resize_handle(v.resizeHandle);
    p->set_timeline_zoom_min(v.timelineZoomMin);
    p->set_timeline_zoom_max(v.timelineZoomMax);
    p->set_timeline_zoom_default(v.timelineZoomDefault);
    p->set_keyframe_size(v.keyframeSize);
    ToProtocol(v.defaultRowColor, p->mutable_default_row_color());
    ToProtocol(v.selectedRowColor, p->mutable_selected_row_color());
    ToProtocol(v.hoverRowColor, p->mutable_hover_row_color());
    ToProtocol(v.invalidHoverRowColor, p->mutable_invalid_hover_row_color());
    ToProtocol(v.defaultLineColor, p->mutable_default_line_color());
    ToProtocol(v.effectViewBackgroundColor, p->mutable_effect_view_background_color());
    ToProtocol(v.effectViewBackgroundColorSelected, p->mutable_effect_view_background_color_selected());
    ToProtocol(v.timelineViewBackgroundColor, p->mutable_timeline_view_background_color());
    ToProtocol(v.effectLineColor, p->mutable_effect_line_color());
    ToProtocol(v.keyframeDefaultColor, p->mutable_keyframe_default_color());
    ToProtocol(v.keyframeSelectedColor, p->mutable_keyframe_selected_color());
    ToProtocol(v.varTextColor, p->mutable_var_text_color());
    ToProtocol(v.varValueColor, p->mutable_var_value_color());
    ToProtocol(v.effectIconExpandedColor, p->mutable_effect_icon_expanded_color());
    ToProtocol(v.effectIconCollapsedColor, p->mutable_effect_icon_collapsed_color());
  }


  inline StyleSetting FromProtocol(const editor::protocol::StyleSetting& p)
  {
    StyleSetting res;
    res.id = p.id();
    res.fillColor = FromProtocol(p.fill_color());
    res.outlineColor = FromProtocol(p.outline_color());
    res.outlineThickness = p.outline_thickness();
    res.fontStyle = p.font_style();
    return res;
  }

  inline void ToProtocol(const StyleSetting& v, editor::protocol::StyleSetting* p)
  {
    p->set_id(v.id);
    ToProtocol(v.fillColor, p->mutable_fill_color());
    ToProtocol(v.outlineColor, p->mutable_outline_color());
    p->set_outline_thickness(v.outlineThickness);
    p->set_font_style(v.fontStyle);
  }


  inline StyleSettings FromProtocol(const editor::protocol::StyleSettings& p)
  {
    StyleSettings res;
    res.styleSetting = FromProtocolRepeated<StyleSetting>(p.style_setting());
    return res;
  }

  inline void ToProtocol(const StyleSettings& v, editor::protocol::StyleSettings* p)
  {
    for (const auto& x : v.styleSetting)
      ToProtocol(x, p->add_style_setting());
  }


  inline EffectSetting FromProtocol(const effect::protocol::EffectSetting& p)
  {
    EffectSetting res;
    res.type = (EffectSetting::Type)p.type();
    res.effectClass = p.effect_class();
    res.id = p.id();
    res.name = p.name();
    res.startTime = p.start_time();
    res.endTime = p.end_time();
    res.configMsg.resize(p.config_msg().size());
    memcpy(res.configMsg.data(), p.config_msg().data(), p.config_msg().size());
    res.configFile = p.config_file();
    return res;
  }

  inline void ToProtocol(const EffectSetting& v, effect::protocol::EffectSetting* p)
  {
    p->set_effect_class(v.effectClass);
    p->set_id(v.id);
    p->set_name(v.name);
    p->set_start_time(v.startTime);
    p->set_end_time(v.endTime);
    p->set_config_file(v.configFile);
  }


  inline EffectSettings FromProtocol(const effect::protocol::EffectSettings& p)
  {
    EffectSettings res;
    res.effectSetting = FromProtocolRepeated<EffectSetting>(p.effect_setting());
    res.soundtrack = p.soundtrack();
    return res;
  }

  inline void ToProtocol(const EffectSettings& v, effect::protocol::EffectSettings* p)
  {
    for (const auto& x : v.effectSetting)
      ToProtocol(x, p->add_effect_setting());
    p->set_soundtrack(v.soundtrack);
  }


  inline Plexus FromProtocol(const effect::protocol::plexus::Plexus& p)
  {
    Plexus res;
    res.textPaths = FromProtocolRepeated<TextPath>(p.text_paths());
    res.noiseEffectors = FromProtocolRepeated<NoiseEffector>(p.noise_effectors());
    return res;
  }

  inline void ToProtocol(const Plexus& v, effect::protocol::plexus::Plexus* p)
  {
    for (const auto& x : v.textPaths)
      ToProtocol(x, p->add_text_paths());
    for (const auto& x : v.noiseEffectors)
      ToProtocol(x, p->add_noise_effectors());
  }


  inline TextPath FromProtocol(const effect::protocol::plexus::TextPath& p)
  {
    TextPath res;
    res.text = p.text();
    return res;
  }

  inline void ToProtocol(const TextPath& v, effect::protocol::plexus::TextPath* p)
  {
    p->set_text(v.text);
  }


  inline Displacement FromProtocol(const effect::protocol::plexus::Displacement& p)
  {
    Displacement res;
    res.x = FromProtocol(p.x());
    res.y = FromProtocol(p.y());
    res.z = FromProtocol(p.z());
    return res;
  }

  inline void ToProtocol(const Displacement& v, effect::protocol::plexus::Displacement* p)
  {
    ToProtocol(v.x, p->mutable_x());
    ToProtocol(v.y, p->mutable_y());
    ToProtocol(v.z, p->mutable_z());
  }


  inline NoiseEffector FromProtocol(const effect::protocol::plexus::NoiseEffector& p)
  {
    NoiseEffector res;
    res.applyTo = (NoiseEffector::ApplyTo)p.apply_to();
    res.displacement = FromProtocol(p.displacement());
    return res;
  }

  inline void ToProtocol(const NoiseEffector& v, effect::protocol::plexus::NoiseEffector* p)
  {
    ToProtocol(v.displacement, p->mutable_displacement());
  }

	
}
