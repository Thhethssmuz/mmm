#pragma once

namespace typefu {

  // recursive multi argument variant of std::is_arithmetic
  template <typename T, typename... Ts>
  struct is_arithmetic {
    static const bool value =
      is_arithmetic<T>::value and is_arithmetic<Ts...>::value;
  };

  template <typename T>
  struct is_arithmetic<T> {
    static const bool value = std::is_arithmetic<T>::value;
  };


  // recursive multi argument variant of std::is_floating_point
  template <typename T, typename... Ts>
  struct is_floating_point {
    static const bool value =
      is_floating_point<T>::value and is_floating_point<Ts...>::value;
  };

  template <typename T>
  struct is_floating_point<T> {
    static const bool value = std::is_floating_point<T>::value;
  };


  // recursive multi argument variant of std::is_integral
  template <typename T, typename... Ts>
  struct is_integral {
    static const bool value =
      is_integral<T>::value and is_integral<Ts...>::value;
  };

  template <typename T>
  struct is_integral<T> {
    static const bool value = std::is_integral<T>::value;
  };


  // recursive multi argument variant of std::is_signed
  template <typename T, typename... Ts>
  struct is_signed {
    static const bool value =
      is_signed<T>::value and is_signed<Ts...>::value;
  };

  template <typename T>
  struct is_signed<T> {
    static const bool value = std::is_signed<T>::value;
  };

  
  // recursive multi argument shorthand for is_signed and is_integral
  template <typename... Ts>
  struct is_signed_integral {
    static const bool value =
      is_signed<Ts...>::value and is_integral<Ts...>::value;
  };


  // recursive multi argument variant of std::is_unsigned
  template <typename T, typename... Ts>
  struct is_unsigned {
    static const bool value =
      is_unsigned<T>::value and is_unsigned<Ts...>::value;
  };

  template <typename T>
  struct is_unsigned<T> {
    static const bool value = std::is_unsigned<T>::value;
  };


  // recursive multi argument reverse ordered variant of std::is_convertible.
  // returns true if all arguments 'From' can be
  // converted to type 'To'.
  template <typename To, typename From, typename... Froms>
  struct is_convertible {
    static const bool value = 
      is_convertible<To,From>::value and is_convertible<To,Froms...>::value;
  };

  template <typename To, typename From>
  struct is_convertible<To, From> {
    static const bool value = std::is_convertible<From, To>::value;
  };
}
