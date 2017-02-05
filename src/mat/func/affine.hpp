#pragma once

template <typename T, size_t N, size_t M = N,
          typename = typefu::for_<N == 2 and M == 2>>
constexpr tmat<T, 2, 2> identity();

template <typename T, size_t N, size_t M = N, typename = typefu::for_<(N > 2)>,
          typename = typefu::for_<(M < N)>>
constexpr tmat<T, N, M> identity();

template <typename T, size_t N, size_t M = N, typename = typefu::for_<(N > 1)>,
          typename = typefu::for_<(M > N)>, typename = void>
constexpr tmat<T, N, M> identity();

template <typename T, size_t N, size_t M = N, typename = typefu::for_<(N > 2)>,
          typename = typefu::for_<M == N>, typename = void, typename = void>
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


template <typename T, typename = typefu::for_floating<T>>
tmat<T, 4, 4> lookAt(const tvec<T, 3>& eye,
                     const tvec<T, 3>& center,
                     const tvec<T, 3>& up);

template <typename T, typename = typefu::for_floating<T>>
tmat<T, 4, 4> perspective(T fovy, T aspect, T near, T far);

template <typename T, typename = typefu::for_floating<T>>
constexpr tmat<T, 4, 4> ortho(T left, T right, T bottom, T top, T near, T far);

template <typename T, typename = typefu::for_floating<T>>
tvec<T, 3> unProject(const tvec<T, 3>& win,
                     const tmat<T, 4, 4>& model,
                     const tmat<T, 4, 4>& proj,
                     const tvec<T, 4>& viewport);
