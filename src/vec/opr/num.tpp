#pragma once

template <typename T, size_t N, typename>
constexpr tvec<T, N> operator+(T s, const tvec<T, N>& v) {
  return tvec<T, N>(s + v.recursive.head, s + v.recursive.tail);
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> operator+(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) + vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator+(const tvec<T, N>& v, T s) {
  return tvec<T, N>(v.recursive.head + s, v.recursive.tail + s);
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> operator+(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) + static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator+(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<T, N>(v.recursive.head + u.recursive.head,
                    v.recursive.tail + u.recursive.tail);
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> operator+(const vecType<T, N, A>& v,
                               const vecType<T, N, B>& u) {
  return vec_cast(v) + vec_cast(u);
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> operator-(const tvec<T, N>& v) {
  return tvec<T, N>(-v.recursive.head, -v.recursive.tail);
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> operator-(const vecType<T, N, A>& v) {
  return -vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator-(T s, const tvec<T, N>& v) {
  return tvec<T, N>(s - v.recursive.head, s - v.recursive.tail);
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> operator-(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) - vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator-(const tvec<T, N>& v, T s) {
  return tvec<T, N>(v.recursive.head - s, v.recursive.tail - s);
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> operator-(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) - static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator-(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<T, N>(v.recursive.head - u.recursive.head,
                    v.recursive.tail - u.recursive.tail);
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> operator-(const vecType<T, N, A>& v,
                               const vecType<T, N, B>& u) {
  return vec_cast(v) - vec_cast(u);
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> operator*(T s, const tvec<T, N>& v) {
  return tvec<T, N>(s * v.recursive.head, s * v.recursive.tail);
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> operator*(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) * vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator*(const tvec<T, N>& v, T s) {
  return tvec<T, N>(v.recursive.head * s, v.recursive.tail * s);
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> operator*(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) * static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator*(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<T, N>(v.recursive.head * u.recursive.head,
                    v.recursive.tail * u.recursive.tail);
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> operator*(const vecType<T, N, A>& v,
                               const vecType<T, N, B>& u) {
  return vec_cast(v) * vec_cast(u);
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> operator/(T s, const tvec<T, N>& v) {
  return tvec<T, N>(s / v.recursive.head, s / v.recursive.tail);
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> operator/(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) / vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator/(const tvec<T, N>& v, T s) {
  return tvec<T, N>(v.recursive.head / s, v.recursive.tail / s);
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> operator/(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) / static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> operator/(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<T, N>(v.recursive.head / u.recursive.head,
                    v.recursive.tail / u.recursive.tail);
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> operator/(const vecType<T, N, A>& v,
                               const vecType<T, N, B>& u) {
  return vec_cast(v) / vec_cast(u);
}
