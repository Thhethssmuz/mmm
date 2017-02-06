#pragma once

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr T sum(const tvec<T, N>& v);

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T sum(const tvec<T, 2>& v);

template <typename T, size_t N, typename A,
          typename = typefu::for_arithmetic<T>>
constexpr T sum(const vecType<T, N, A>& v);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr T product(const tvec<T, N>& v);

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T product(const tvec<T, 2>& v);

template <typename T, size_t N, typename A,
          typename = typefu::for_arithmetic<T>>
constexpr T product(const vecType<T, N, A>& v);


template <size_t N, typename T, size_t L, typename = typefu::for_<(N <= L)>,
          typename = typefu::for_<(N > 1)>>
constexpr tvec<T, N> take(const tvec<T, L>& v);

template <size_t N, typename T, size_t L, typename A,
          typename = typefu::for_<(N <= L)>, typename = typefu::for_<(N > 1)>>
constexpr tvec<T, N> take(const vecType<T, L, A>& v);

template <size_t N, typename T, size_t L, typename = typefu::for_<(N == 1)>>
constexpr T take(const tvec<T, L>& v);

template <size_t N, typename T, size_t L, typename A,
          typename = typefu::for_<(N == 1)>>
constexpr T take(const vecType<T, L, A>& v);

template <size_t N, typename T, typename = typefu::for_<(N == 1)>>
constexpr T take(T x);


template <size_t N, typename T, size_t L,
          typename = typefu::for_<(L - N > 1 and N > 0)>>
constexpr tvec<T, L - N> drop(const tvec<T, L>& v);

template <size_t N, typename T, size_t L, typename = typefu::for_<(L - N > 1)>,
          typename = typefu::for_<(N == 0)>>
constexpr tvec<T, L - N> drop(const tvec<T, L>& v);

template <size_t N, typename T, size_t L, typename A,
          typename = typefu::for_<(L - N > 1)>>
constexpr tvec<T, L - N> drop(const vecType<T, L, A>& v);

template <size_t N, typename T, size_t L, typename = typefu::for_<(L - N == 1)>>
constexpr T drop(const tvec<T, L>& v);

template <size_t N, typename T, size_t L, typename A,
          typename = typefu::for_<(L - N == 1)>>
constexpr T drop(const vecType<T, L, A>& v);
