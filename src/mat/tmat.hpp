#pragma once

// matrix with N columns and M rows
template <typename T, size_t N, size_t M>
struct tmat {

  static_assert(N > 1, "matrices must have at least 2 columns");
  static_assert(M > 1, "matrices must have at least 2 rows");

  struct R {
    tvec<T, N> head;
    tmat<T, N, M - 1> tail;
  };

  union {
    T rawdata[N * M];
    tvec<T, N> data[M];
    R recursive;
  };

  constexpr tmat();
  explicit constexpr tmat(T x);
  explicit constexpr tmat(const tvec<T, N>& v, tmat<T, N, M - 1>&& vs);
  explicit constexpr tmat(const tvec<T, N>& v, const tmat<T, N, M - 1>& vs);

  constexpr tmat(tmat<T, N, M>&& m);
  constexpr tmat(const tmat<T, N, M>& m);

  template <size_t L, typename = typefu::for_<L >= N * M>>
  explicit constexpr tmat(const tvec<T, L>&);

  template <typename... Ts, typename = typefu::for_components<N * M, Ts...>>
  explicit constexpr tmat(Ts... xs);

  constexpr tvec<T, N> operator[](size_t i) const;
  tvec<T, N>& operator[](size_t i);
  operator T*();

  tmat<T, N, M>& operator=(const tmat<T, N, M>& m);

  static const tmat<T, N, M> identity;
};
