#pragma once

template <typename T, size_t N, typename>
tvec<T, N>& operator+=(tvec<T, N>& v, T s) {
  v.recursive.head += s;
  v.recursive.tail += s;
  return v;
}
template <typename T, typename U, size_t N, typename>
tvec<T, N>& operator+=(tvec<T, N>& v, U s) {
  return v += static_cast<T>(s);
}
template <typename T, size_t N, typename>
tvec<T, N>& operator+=(tvec<T, N>& v, const tvec<T, N>& u) {
  v.recursive.head += u.recursive.head;
  v.recursive.tail += u.recursive.tail;
  return v;
}
template <typename T, size_t N, typename A, typename>
tvec<T, N>& operator+=(tvec<T, N>& v, const vecType<T, N, A>& u) {
  return v += vec_cast(u);
}


template <typename T, size_t N, typename>
tvec<T, N>& operator-=(tvec<T, N>& v, T s) {
  v.recursive.head -= s;
  v.recursive.tail -= s;
  return v;
}
template <typename T, typename U, size_t N, typename>
tvec<T, N>& operator-=(tvec<T, N>& v, U s) {
  return v -= static_cast<T>(s);
}
template <typename T, size_t N, typename>
tvec<T, N>& operator-=(tvec<T, N>& v, const tvec<T, N>& u) {
  v.recursive.head -= u.recursive.head;
  v.recursive.tail -= u.recursive.tail;
  return v;
}
template <typename T, size_t N, typename A, typename>
tvec<T, N>& operator-=(tvec<T, N>& v, const vecType<T, N, A>& u) {
  return v -= vec_cast(u);
}


template <typename T, size_t N, typename>
tvec<T, N>& operator*=(tvec<T, N>& v, T s) {
  v.recursive.head *= s;
  v.recursive.tail *= s;
  return v;
}
template <typename T, typename U, size_t N, typename>
tvec<T, N>& operator*=(tvec<T, N>& v, U s) {
  return v *= static_cast<T>(s);
}
template <typename T, size_t N, typename>
tvec<T, N>& operator*=(tvec<T, N>& v, const tvec<T, N>& u) {
  v.recursive.head *= u.recursive.head;
  v.recursive.tail *= u.recursive.tail;
  return v;
}
template <typename T, size_t N, typename A, typename>
tvec<T, N>& operator*=(tvec<T, N>& v, const vecType<T, N, A>& u) {
  return v *= vec_cast(u);
}


template <typename T, size_t N, typename>
tvec<T, N>& operator/=(tvec<T, N>& v, T s) {
  v.recursive.head /= s;
  v.recursive.tail /= s;
  return v;
}
template <typename T, typename U, size_t N, typename>
tvec<T, N>& operator/=(tvec<T, N>& v, U s) {
  return v /= static_cast<T>(s);
}
template <typename T, size_t N, typename>
tvec<T, N>& operator/=(tvec<T, N>& v, const tvec<T, N>& u) {
  v.recursive.head /= u.recursive.head;
  v.recursive.tail /= u.recursive.tail;
  return v;
}
template <typename T, size_t N, typename A, typename>
tvec<T, N>& operator/=(tvec<T, N>& v, const vecType<T, N, A>& u) {
  return v /= vec_cast(u);
}
