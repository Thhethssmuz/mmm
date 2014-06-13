#ifndef mmm_typefu_restrict_hpp
#define mmm_typefu_restrict_hpp

namespace typefu {

  template <bool... Bs>
  using for_ = typename std::enable_if<all<Bs...>::value>::type;


  template <typename... Ts>
  using for_arithmetic =
    typename std::enable_if<is_arithmetic<Ts...>::value>::type;

  template <typename... Ts>
  using for_floating =
    typename std::enable_if<is_floating_point<Ts...>::value>::type;

  template <typename... Ts>
  using for_integral = typename std::enable_if<is_integral<Ts...>::value>::type;

  template <typename... Ts>
  using for_signed = typename std::enable_if<is_signed<Ts...>::value>::type;

  template <typename... Ts>
  using for_signed_integral =
    typename std::enable_if<is_signed_integral<Ts...>::value>::type;

  template <typename... Ts>
  using for_unsigned = typename std::enable_if<is_unsigned<Ts...>::value>::type;

  template <typename... Ts>
  using for_convertible =
    typename std::enable_if<is_convertible<Ts...>::value>::type;
}

#endif