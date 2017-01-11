#pragma once

template <typename T, size_t N, typename A>
struct vecType;

template <typename T, size_t N>
struct tvec : vecType<T, N, tvec<T, N>> {

  static_assert(N > 1, "vectors must have at least 2 elements");

  struct R {
    T head;
    tvec<T, N - 1> tail;
  };

  union {
    T data[N];
    R recursive;

#include <swizzle/swizzle_declarations.tpp>
  };

  constexpr tvec();
  explicit constexpr tvec(T x);
  explicit constexpr tvec(T x, tvec<T, N - 1>&& xs);
  explicit constexpr tvec(T x, const tvec<T, N - 1>& xs);

  constexpr tvec(tvec<T, N>&& v);
  constexpr tvec(const tvec<T, N>& v);


  template <typename U, typename = typefu::for_convertible<T, U>>
  explicit constexpr tvec(const tvec<U, N>& v);

  template <typename U, typename A, typename = typefu::for_convertible<T, U>>
  explicit constexpr tvec(const vecType<U, N, A>& v);


  template <typename... Ts, typename = typefu::for_components<N, T, Ts...>>
  constexpr tvec(T x, Ts... xs);

  template <size_t L, typename... Ts,
            typename = typefu::for_components<N, tvec<T, L>, Ts...>>
  explicit constexpr tvec(const tvec<T, L>& xs, Ts... ys);

  template <size_t L, size_t... Elems, typename... Ts,
            typename =
              typefu::for_components<N, swizzle<T, L, Elems...>, Ts...>>
  explicit constexpr tvec(const swizzle<T, L, Elems...>& xs, Ts... ys);

  template <size_t L, size_t K, typename... Ts,
            typename = typefu::for_components<N, tmat<T, L, K>, Ts...>>
  explicit constexpr tvec(const tmat<T, L, K>& xs, Ts... ys);


  constexpr T operator[](size_t i) const;
  T& operator[](size_t i);
  operator T*();

  tvec<T, N>& operator=(const tvec<T, N>& v);

  template <size_t... Elems>
  swizzle<T, N, Elems...>& swizzleElems();

  template <size_t Start, size_t End>
  typefu::swizzle_range<T, N, Start, End>& swizzleRange();
};
