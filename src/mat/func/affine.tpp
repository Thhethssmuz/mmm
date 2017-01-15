#pragma once

template <typename T, size_t N, size_t E, typename>
constexpr tvec<T, N> build_identity_row() {
  return tvec<T, N>(
    E == 1 ? T(1) : T(0), build_identity_row<T, N - 1, E == 0 ? 0 : E - 1>());
}
template <typename T, size_t N, size_t E, typename, typename, typename>
constexpr tvec<T, N> build_identity_row() {
  return tvec<T, N>(E == 1 ? T(1) : T(0), E == 2 ? T(1) : T(0));
}

template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> identity() {
  return tmat<T, N, M>(build_identity_row<T, M, M - N + 1>(),
                       identity<T, N - 1, M>());
}
template <typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N, M> identity() {
  return tmat<T, N, M>(build_identity_row<T, M, M - 1>(),
                       build_identity_row<T, M, M>());
}

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M> tmat<T, N, M>::identity = mmm::identity<T, N, M>();

template <typename T, size_t M>
constexpr tmat<T, 2, M> tmat<T, 2, M>::identity = mmm::identity<T, 2, M>();


template <typename T, typename>
constexpr tmat<T, 4, 4> translate(T x, T y, T z) {
  return tmat<T, 4, 4>(1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z, 0, 0, 0, 1);
}
template <typename T, typename>
constexpr tmat<T, 4, 4> translate(const tvec<T, 3>& v) {
  return tmat<T, 4, 4>(1, 0, 0, v[0], 0, 1, 0, v[1], 0, 0, 1, v[2], 0, 0, 0, 1);
}


template <typename T, typename>
constexpr tmat<T, 4, 4> rotate_x(T d) {
  return tmat<T, 4, 4>(
    1, 0, 0, 0,
    0, cos(d * constants<T>::pi / T(180)), -sin(d * constants<T>::pi / T(180)), 0,
    0, sin(d * constants<T>::pi / T(180)), cos(d * constants<T>::pi / T(180)), 0,
    0, 0, 0, 1);
}
template <typename T, typename>
constexpr tmat<T, 4, 4> rotate_y(T d) {
  return tmat<T, 4, 4>(
    cos(d * constants<T>::pi / T(180)), 0, sin(d * constants<T>::pi / T(180)), 0,
    0, 1, 0, 0,
    -sin(d * constants<T>::pi / T(180)), 0, cos(d * constants<T>::pi / T(180)), 0,
    0, 0, 0, 1);
}
template <typename T, typename>
constexpr tmat<T, 4, 4> rotate_z(T d) {
  return tmat<T, 4, 4>(
    cos(d * constants<T>::pi / T(180)), -sin(d * constants<T>::pi / T(180)), 0, 0,
    sin(d * constants<T>::pi / T(180)), cos(d * constants<T>::pi / T(180)), 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1);
}
template <typename T, typename>
constexpr tmat<T, 4, 4> rotate(T x, T y, T z) {
  return rotate_z(z) * rotate_y(y) * rotate_x(x);
}
template <typename T, typename>
constexpr tmat<T, 4, 4> rotate(const tvec<T, 3>& v) {
  return rotate_z(v.z) * rotate_y(v.y) * rotate_x(v.x);
}


template <typename T, typename>
constexpr tmat<T, 4, 4> scale(T x, T y, T z) {
  return tmat<T, 4, 4>(x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1);
}
template <typename T, typename>
constexpr tmat<T, 4, 4> scale(const tvec<T, 3>& v) {
  return tmat<T, 4, 4>(v[0], 0, 0, 0, 0, v[1], 0, 0, 0, 0, v[2], 0, 0, 0, 0, 1);
}
