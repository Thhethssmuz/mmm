#pragma once

namespace typefu {

  template <typename T, bool = is_integral<T>::value>
  struct promote_to_floating {
    typedef double type;
  };

  template <typename T>
  struct promote_to_floating<T, false> {
    static_assert(is_arithmetic<T>::value, "undefined floating promotion");
    typedef T type;
  };


  template <typename T, typename... Ts>
  struct floating_promotion {
    typedef typename floating_promotion<T>::type type1;
    typedef typename floating_promotion<Ts...>::type type2;

    typedef decltype(type1() + type2()) type;
  };

  template <typename T, typename U>
  struct floating_promotion<T, U> {
    typedef typename floating_promotion<T>::type type1;
    typedef typename floating_promotion<U>::type type2;

    typedef decltype(type1() + type2()) type;
  };

  template <typename T>
  struct floating_promotion<T> {
    typedef typename promote_to_floating<T>::type type;
  };


  template <typename T, typename... Ts>
  struct arithmetic_promotion {
    typedef typename arithmetic_promotion<T>::type type1;
    typedef typename arithmetic_promotion<Ts...>::type type2;

    typedef decltype(type1() + type2()) type;
  };

  template <typename T, typename U>
  struct arithmetic_promotion<T, U> {
    typedef typename arithmetic_promotion<T>::type type1;
    typedef typename arithmetic_promotion<U>::type type2;

    typedef decltype(type1() + type2()) type;
  };

  template <typename T>
  struct arithmetic_promotion<T> {
    static_assert(is_arithmetic<T>::value, "undefined arithmetic promotion");
    typedef T type;
  };


  template <typename... Ts>
  using promote = typename arithmetic_promotion<Ts...>::type;

  template <typename... Ts>
  using promotef = typename floating_promotion<Ts...>::type;
}
