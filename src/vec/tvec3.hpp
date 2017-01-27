#pragma once

template <typename T>
struct tvec<T, 3> : vecType<T, 3, tvec<T, 3>> {

  struct R {
    T head;
    tvec<T, 2> tail;
  };

  union {
    T data[3];
    R recursive;

#   define N 3
#   include <swizzle/swizzle_declarations.tpp>
#   undef N
  };

  constexpr tvec();
  explicit constexpr tvec(T x);
  explicit constexpr tvec(T x, tvec<T, 2>&& xs);
  explicit constexpr tvec(T x, const tvec<T, 2>& xs);

  constexpr tvec(tvec<T, 3>&& v);
  constexpr tvec(const tvec<T, 3>& v);


  template <typename U, typename = typefu::for_convertible<T, U>>
  explicit constexpr tvec(const tvec<U, 3>& v);

  template <typename U, typename A, typename = typefu::for_convertible<T, U>>
  explicit constexpr tvec(const vecType<U, 3, A>& v);


  template <typename... Ts, typename = typefu::for_components<3, T, Ts...>>
  constexpr tvec(T x, Ts... xs);

  template <size_t L, typename... Ts,
            typename = typefu::for_components<3, tvec<T, L>, Ts...>>
  explicit constexpr tvec(const tvec<T, L>& xs, Ts... ys);

  template <size_t L, size_t... Elems, typename... Ts,
            typename =
              typefu::for_components<3, swizzle<T, L, Elems...>, Ts...>>
  explicit constexpr tvec(const swizzle<T, L, Elems...>& xs, Ts... ys);

  template <size_t L, size_t K, typename... Ts,
            typename = typefu::for_components<3, tmat<T, L, K>, Ts...>>
  explicit constexpr tvec(const tmat<T, L, K>& xs, Ts... ys);


  constexpr T operator[](size_t i) const;
  T& operator[](size_t i);
  operator T*();

  tvec<T, 3>& operator=(const tvec<T, 3>& v);

  template <size_t... Elems>
  swizzle<T, 3, Elems...>& swizzleElems();

  template <size_t Start, size_t End>
  typefu::swizzle_range<T, 3, Start, End>& swizzleRange();
};
