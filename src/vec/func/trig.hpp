#pragma once

// all trigonometric functions are only defined for floating point types and
// floating vector types.

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> radians(T degrees);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> radians(const tvec<T, N>& degrees);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> radians(const vecType<T, N, A>& degrees);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> degrees(T radians);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> degrees(const tvec<T, N>& radians);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> degrees(const vecType<T, N, A>& radians);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> sin(T angle);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> sin(const tvec<T, N>& angle);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> sin(const vecType<T, N, A>& angle);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> cos(T angle);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> cos(const tvec<T, N>& angle);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> cos(const vecType<T, N, A>& angle);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> tan(T angle);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> tan(const tvec<T, N>& angle);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> tan(const vecType<T, N, A>& angle);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> asin(T x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> asin(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> asin(const vecType<T, N, A>& x);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> acos(T x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> acos(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> acos(const vecType<T, N, A>& x);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> atan(T y_over_x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> atan(const tvec<T, N>& y_over_x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> atan(const vecType<T, N, A>& y_over_x);


template <typename T, typename = typefu::for_floating<T>>
constexpr T atan(T y, T x);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promotef<T, U> atan(T y, U x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> atan(T y, const tvec<T, N>& x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, N> atan(U y, const vecType<T, N, A>& x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> atan(const tvec<T, N>& y, T x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, N> atan(const vecType<T, N, A>& y, U x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> atan(const tvec<T, N>& y, const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_floating<T>>
constexpr tvec<T, N> atan(const vecType<T, N, A>& y, const vecType<T, N, B>& x);
