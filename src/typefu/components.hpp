#ifndef mmm_typefu_components_hpp
#define mmm_typefu_components_hpp

template <typename T, size_t n, typename A>
struct vecType;

template <typename T, size_t n>
struct tvec;

template <typename T, size_t n, size_t... elems>
struct swizzle;

namespace typefu {

  template <typename T, typename... Ts>
  struct vec_components {
    static const size_t value = 1 + vec_components<Ts...>::value;
  };

  template <typename T, size_t n, typename... Ts>
  struct vec_components<tvec<T, n>, Ts...> {
    static const size_t value = n + vec_components<Ts...>::value;
  };

  template <typename T, size_t n, size_t... elems, typename... Ts>
  struct vec_components<swizzle<T, n, elems...>, Ts...> {
    static const size_t value = sizeof...(elems) + vec_components<Ts...>::value;
  };

  template <typename T, size_t n, typename A, typename... Ts>
  struct vec_components<vecType<T, n, A>, Ts...> {
    static const size_t value = n + vec_components<Ts...>::value;
  };


  template <typename T>
  struct vec_components<T> {
    static const size_t value = 1;
  };

  template <typename T, size_t n>
  struct vec_components<tvec<T, n>> {
    static const size_t value = n;
  };

  template <typename T, size_t n, size_t... elems>
  struct vec_components<swizzle<T, n, elems...>> {
    static const size_t value = sizeof...(elems);
  };

  template <typename T, size_t n, typename A>
  struct vec_components<vecType<T, n, A>> {
    static const size_t value = n;
  };


  template <size_t n, typename... Ts>
  using for_components =
    typename std::enable_if<vec_components<Ts...>::value >= n>::type;
}

#endif