#ifndef mmm_typefu_components_hpp
#define mmm_typefu_components_hpp

template <typename T, size_t N, typename A>
struct vecType;

template <typename T, size_t N>
struct tvec;

template <typename T, size_t N, size_t... Elems>
struct swizzle;

template <typename T, size_t N, size_t M>
struct tmat;

namespace typefu {

  template <typename T, typename... Ts>
  struct components {
    static constexpr size_t value = 1 + components<Ts...>::value;
  };

  template <typename T, size_t N, typename... Ts>
  struct components<tvec<T, N>, Ts...> {
    static constexpr size_t value = N + components<Ts...>::value;
  };

  template <typename T, size_t N, size_t... Elems, typename... Ts>
  struct components<swizzle<T, N, Elems...>, Ts...> {
    static constexpr size_t value = sizeof...(Elems) + components<Ts...>::value;
  };

  template <typename T, size_t N, typename A, typename... Ts>
  struct components<vecType<T, N, A>, Ts...> {
    static constexpr size_t value = N + components<Ts...>::value;
  };

  template <typename T, size_t N, size_t M, typename... Ts>
  struct components<tmat<T, N, M>, Ts...> {
    static constexpr size_t value = N * M + components<Ts...>::value;
  };


  template <typename T>
  struct components<T> {
    static constexpr size_t value = 1;
  };

  template <typename T, size_t N>
  struct components<tvec<T, N>> {
    static constexpr size_t value = N;
  };

  template <typename T, size_t N, size_t... Elems>
  struct components<swizzle<T, N, Elems...>> {
    static constexpr size_t value = sizeof...(Elems);
  };

  template <typename T, size_t N, typename A>
  struct components<vecType<T, N, A>> {
    static constexpr size_t value = N;
  };

  template <typename T, size_t N, size_t M>
  struct components<tmat<T, N, M>> {
    static constexpr size_t value = N * M;
  };

  template <size_t N, typename... Ts>
  using for_components =
    typename std::enable_if<components<Ts...>::value >= N>::type;
}

#endif