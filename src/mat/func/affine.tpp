#pragma once

template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, 2, 2> identity() {
  return tmat<T, 2, 2>(1, 0, 0, 1);
}
template <typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N, M> identity() {
  return appendColumn(identity<T, N - 1, M>(), tvec<T, M>(0));
}
template <typename T, size_t N, size_t M, typename, typename, typename>
constexpr tmat<T, N, M> identity() {
  return appendRow(identity<T, N, M - 1>(), tvec<T, N>(0));
}
template <typename T, size_t N, size_t M, typename, typename, typename,
          typename>
constexpr tmat<T, N, M> identity() {
  return appendRow(appendColumn(identity<T, N - 1, M - 1>(), tvec<T, M - 1>(0)),
                   tvec<T, N>(tvec<T, N - 1>(0), 1));
}


template <typename T, size_t N>
constexpr tmat<T, N, 2> tmat<T, N, 2>::identity = mmm::identity<T, N, 2>();

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M> tmat<T, N, M>::identity = mmm::identity<T, N, M>();


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


template <typename T, typename>
tmat<T, 4, 4> lookAt(const tvec<T, 3>& eye,
                     const tvec<T, 3>& center,
                     const tvec<T, 3>& up) {
  return lookAt_l(eye, center, up);
}
template <typename T, typename>
tmat<T, 4, 4> lookAt_l(const tvec<T, 3>& eye,
                       const tvec<T, 3>& center,
                       const tvec<T, 3>& up) {

  tvec<T, 3> f = normalize(center - eye);
  tvec<T, 3> u = normalize(up);
  tvec<T, 3> s = normalize(cross(u, f));
  u = cross(f, s);

  return tmat<T, 4, 4>(
    s.x, s.y, s.z, -dot(s, eye),
    u.x, u.y, u.z, -dot(u, eye),
    f.x, f.y, f.z, -dot(f, eye),
    0, 0, 0, 1);
}
template <typename T, typename>
tmat<T, 4, 4> lookAt_r(const tvec<T, 3>& eye,
                       const tvec<T, 3>& center,
                       const tvec<T, 3>& up) {

  tvec<T, 3> f = normalize(center - eye);
  tvec<T, 3> u = normalize(up);
  tvec<T, 3> s = normalize(cross(f, u));
  u = cross(s, f);

  return tmat<T, 4, 4>(
    s.x, s.y, s.z, -dot(s, eye),
    u.x, u.y, u.z, -dot(u, eye),
    -f.x, -f.y, -f.z, dot(f, eye),
    0, 0, 0, 1);
}


template <typename T, typename>
tmat<T, 4, 4> perspective(T fovy, T aspect, T near, T far) {
  return perspective_l(fovy, aspect, near, far);
}
template <typename T, typename>
tmat<T, 4, 4> perspective_l(T fovy, T aspect, T near, T far) {

  T r  = tan(fovy * constants<T>::pi / T(360)) * near;
  T sx = (T(2) * near) / (r * aspect + r * aspect);
  T sy = near / r;
  T sz = (far + near) / (far - near);
  T pz = -(T(2) * far * near) / (far - near);

  return tmat<T, 4, 4>(sx, 0, 0, 0, 0, sy, 0, 0, 0, 0, sz, pz, 0, 0, 1, 0);
}
template <typename T, typename>
tmat<T, 4, 4> perspective_r(T fovy, T aspect, T near, T far) {

  T r  = tan(fovy * constants<T>::pi / T(360)) * near;
  T sx = (T(2) * near) / (r * aspect + r * aspect);
  T sy = near / r;
  T sz = -(far + near) / (far - near);
  T pz = -(T(2) * far * near) / (far - near);

  return tmat<T, 4, 4>(sx, 0, 0, 0, 0, sy, 0, 0, 0, 0, sz, pz, 0, 0, -1, 0);
}


template <typename T, typename>
constexpr tmat<T, 4, 4> ortho(T left, T right, T bottom, T top, T near, T far) {
  return ortho_l(left, right, bottom, top, near, far);
}
template <typename T, typename>
constexpr tmat<T, 4, 4> ortho_l(T left, T right, T bottom, T top, T near, T far) {
  return tmat<T, 4, 4>(
    T(2) / (right - left), 0, 0, -(right + left) / (right - left),
    0, T(2) / (top - bottom), 0, -(top + bottom) / (top - bottom),
    0, 0, T(2) / (far - near), -(far + near) / (far - near),
    0, 0, 0, 1);
}
template <typename T, typename>
constexpr tmat<T, 4, 4> ortho_r(T left, T right, T bottom, T top, T near, T far) {
  return tmat<T, 4, 4>(
    T(2) / (right - left), 0, 0, -(right + left) / (right - left),
    0, T(2) / (top - bottom), 0, -(top + bottom) / (top - bottom),
    0, 0, T(-2) / (far - near), -(far + near) / (far - near),
    0, 0, 0, 1);
}


template <typename T, typename>
tvec<T, 3> unProject(const tvec<T, 3>& win,
                     const tmat<T, 4, 4>& model,
                     const tmat<T, 4, 4>& proj,
                     const tvec<T, 4>& viewport) {

  tvec<T, 4> d = vec4(win, T(1));

  d.x = (d.x - viewport.x) / viewport.z;
  d.y = (d.y - viewport.y) / viewport.w;
  d   = inverse(proj * model) * (d * T(2) - T(1));

  return tvec<T, 3>(d / d.w);
}
