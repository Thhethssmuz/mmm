#pragma once

template <typename T, size_t N, size_t E,
          typename = typefu::for_<(N > 2)>>
constexpr tvec<T, N> build_identity_row();

template <typename T, size_t N, size_t E, typename = typefu::for_<N == 2>,
          typename = void, typename = void>
constexpr tvec<T, N> build_identity_row();


template <typename T, size_t N, size_t M = N, typename = typefu::for_<(N > 2)>>
constexpr tmat<T, N, M> identity();

template <typename T, size_t N, size_t M = N, typename = typefu::for_<N == 2>,
          typename = void>
constexpr tmat<T, N, M> identity();


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, 4, 4> translate(T x, T y, T z);

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, 4, 4> translate(const tvec<T, 3>& v);


template <typename T, typename = typefu::for_floating<T>>
constexpr tmat<T, 4, 4> rotate_x(T x);

template <typename T, typename = typefu::for_floating<T>>
constexpr tmat<T, 4, 4> rotate_y(T x);

template <typename T, typename = typefu::for_floating<T>>
constexpr tmat<T, 4, 4> rotate_z(T x);

template <typename T, typename = typefu::for_floating<T>>
constexpr tmat<T, 4, 4> rotate(T x, T y, T z);

template <typename T, typename = typefu::for_floating<T>>
constexpr tmat<T, 4, 4> rotate(const tvec<T, 3>& v);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, 4, 4> scale(T x, T y, T z);

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, 4, 4> scale(const tvec<T, 3>& v);
