#pragma once

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator+(T s, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> operator+(U s, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator+(const tvec<T, N>& v, T s);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> operator+(const vecType<T, N, A>& v, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator+(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator+(const vecType<T, N, A>& v,
                               const vecType<T, N, B>& u);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator-(const tvec<T, N>& v);

template <typename T, size_t N, typename A,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator-(const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator-(T s, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> operator-(U s, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator-(const tvec<T, N>& v, T s);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> operator-(const vecType<T, N, A>& v, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator-(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator-(const vecType<T, N, A>& v,
                               const vecType<T, N, B>& u);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator*(T s, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> operator*(U s, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator*(const tvec<T, N>& v, T s);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> operator*(const vecType<T, N, A>& v, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator*(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator*(const vecType<T, N, A>& v,
                               const vecType<T, N, B>& u);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator/(T s, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> operator/(U s, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator/(const tvec<T, N>& v, T s);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> operator/(const vecType<T, N, A>& v, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator/(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator/(const vecType<T, N, A>& v,
                               const vecType<T, N, B>& u);
