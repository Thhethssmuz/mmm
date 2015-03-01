#pragma once

template <typename T, size_t N, size_t M, typename>
tmat<T, N, M>& operator+=(tmat<T, N, M>& m, T s) {
  m.recursive.head += s;
  m.recursive.tail += s;
  return m;
}
template <typename T, typename U, size_t N, size_t M, typename>
tmat<T, N, M>& operator+=(tmat<T, N, M>& m, U s) {
  return m += static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
tmat<T, N, M>& operator+=(tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  m.recursive.head += n.recursive.head;
  m.recursive.tail += n.recursive.tail;
  return m;
}


template <typename T, size_t N, size_t M, typename>
tmat<T, N, M>& operator-=(tmat<T, N, M>& m, T s) {
  m.recursive.head -= s;
  m.recursive.tail -= s;
  return m;
}
template <typename T, typename U, size_t N, size_t M, typename>
tmat<T, N, M>& operator-=(tmat<T, N, M>& m, U s) {
  return m -= static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
tmat<T, N, M>& operator-=(tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  m.recursive.head -= n.recursive.head;
  m.recursive.tail -= n.recursive.tail;
  return m;
}


template <typename T, size_t N, size_t M, typename>
tmat<T, N, M>& operator*=(tmat<T, N, M>& m, T s) {
  m.recursive.head *= s;
  m.recursive.tail *= s;
  return m;
}
template <typename T, typename U, size_t N, size_t M, typename>
tmat<T, N, M>& operator*=(tmat<T, N, M>& m, U s) {
  return m *= static_cast<T>(s);
}
template <typename T, size_t N, typename>
tmat<T, N, N>& operator*=(tmat<T, N, N>& m, const tmat<T, N, N>& n) {
  m = m * n;
  return m;
}


template <typename T, size_t N, size_t M, typename>
tmat<T, N, M>& operator/=(tmat<T, N, M>& m, T s) {
  m.recursive.head /= s;
  m.recursive.tail /= s;
  return m;
}
template <typename T, typename U, size_t N, size_t M, typename>
tmat<T, N, M>& operator/=(tmat<T, N, M>& m, U s) {
  return m /= static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
tmat<T, N, M>& operator/=(tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  m.recursive.head /= n.recursive.head;
  m.recursive.tail /= n.recursive.tail;
  return m;
}
