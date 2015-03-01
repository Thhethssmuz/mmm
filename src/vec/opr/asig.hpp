#pragma once

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator+=(tvec<T, N>& v, T s);

template <typename T, typename U, size_t N,
          typename = typefu::for_arithmetic<T, U>>
tvec<T, N>& operator+=(tvec<T, N>& v, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator+=(tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A,
          typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator+=(tvec<T, N>& v, const vecType<T, N, A>& u);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator-=(tvec<T, N>& v, T s);

template <typename T, typename U, size_t N,
          typename = typefu::for_arithmetic<T, U>>
tvec<T, N>& operator-=(tvec<T, N>& v, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator-=(tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A,
          typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator-=(tvec<T, N>& v, const vecType<T, N, A>& u);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator*=(tvec<T, N>& v, T s);

template <typename T, typename U, size_t N,
          typename = typefu::for_arithmetic<T, U>>
tvec<T, N>& operator*=(tvec<T, N>& v, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator*=(tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A,
          typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator*=(tvec<T, N>& v, const vecType<T, N, A>& u);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator/=(tvec<T, N>& v, T s);

template <typename T, typename U, size_t N,
          typename = typefu::for_arithmetic<T, U>>
tvec<T, N>& operator/=(tvec<T, N>& v, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator/=(tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A,
          typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator/=(tvec<T, N>& v, const vecType<T, N, A>& u);
