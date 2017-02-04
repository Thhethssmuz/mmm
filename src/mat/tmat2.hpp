#pragma once

// matrix with N columns and 2 rows
template <typename T, size_t N>
struct tmat<T, N, 2> {

  static_assert(N > 1, "matrices must have at least 2 columns");

  struct R {
    tvec<T, N> head;
    tvec<T, N> tail;
  };

  union {
    T rawdata[N * 2];
    tvec<T, N> data[2];
    R recursive;
  };

  constexpr tmat();
  explicit constexpr tmat(T x);
  explicit constexpr tmat(const tvec<T, N>& v, const tvec<T, N>& u);

  constexpr tmat(tmat<T, N, 2>&& m);
  constexpr tmat(const tmat<T, N, 2>& m);

  template <size_t L, typename = typefu::for_<L >= N * 2>>
  explicit constexpr tmat(const tvec<T, L>& xs);

  template <typename... Ts, typename = typefu::for_components<N * 2, Ts...>>
  explicit constexpr tmat(Ts... xs);

  constexpr tvec<T, N> operator[](size_t i) const;
  tvec<T, N>& operator[](size_t i);
  operator T*();

  tmat<T, N, 2>& operator=(const tmat<T, N, 2>& m);

  static const tmat<T, N, 2> identity;
};
