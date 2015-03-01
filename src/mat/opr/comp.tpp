#pragma once

template <typename T, size_t N, size_t M, typename>
constexpr bool operator>(T s, const tmat<T, N, M>& m) {
  return s > m.recursive.head and s > m.recursive.tail;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator>(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) > m;
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator>(const tmat<T, N, M>& m, T s) {
  return m.recursive.head > s and m.recursive.tail > s;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator>(const tmat<T, N, M>& m, U s) {
  return m > static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator>(const tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  return m.recursive.head > n.recursive.head and m.recursive.tail >
         n.recursive.tail;
}


template <typename T, size_t N, size_t M, typename>
constexpr bool operator>=(T s, const tmat<T, N, M>& m) {
  return s >= m.recursive.head and s >= m.recursive.tail;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator>=(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) >= m;
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator>=(const tmat<T, N, M>& m, T s) {
  return m.recursive.head >= s and m.recursive.tail >= s;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator>=(const tmat<T, N, M>& m, U s) {
  return m >= static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator>=(const tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  return m.recursive.head >= n.recursive.head and m.recursive.tail >=
         n.recursive.tail;
}


template <typename T, size_t N, size_t M, typename>
constexpr bool operator<=(T s, const tmat<T, N, M>& m) {
  return s <= m.recursive.head and s <= m.recursive.tail;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator<=(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) <= m;
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator<=(const tmat<T, N, M>& m, T s) {
  return m.recursive.head <= s and m.recursive.tail <= s;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator<=(const tmat<T, N, M>& m, U s) {
  return m <= static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator<=(const tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  return m.recursive.head <= n.recursive.head and m.recursive.tail <=
         n.recursive.tail;
}


template <typename T, size_t N, size_t M, typename>
constexpr bool operator<(T s, const tmat<T, N, M>& m) {
  return s < m.recursive.head and s < m.recursive.tail;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator<(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) < m;
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator<(const tmat<T, N, M>& m, T s) {
  return m.recursive.head < s and m.recursive.tail < s;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator<(const tmat<T, N, M>& m, U s) {
  return m < static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator<(const tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  return m.recursive.head < n.recursive.head and m.recursive.tail <
         n.recursive.tail;
}


template <typename T, size_t N, size_t M, typename>
constexpr bool operator==(T s, const tmat<T, N, M>& m) {
  return s == m.recursive.head and s == m.recursive.tail;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator==(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) == m;
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator==(const tmat<T, N, M>& m, T s) {
  return m.recursive.head == s and m.recursive.tail == s;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator==(const tmat<T, N, M>& m, U s) {
  return m == static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator==(const tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  return m.recursive.head == n.recursive.head and m.recursive.tail ==
         n.recursive.tail;
}


template <typename T, size_t N, size_t M, typename>
constexpr bool operator!=(T s, const tmat<T, N, M>& m) {
  return s != m.recursive.head or s != m.recursive.tail;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator!=(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) != m;
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator!=(const tmat<T, N, M>& m, T s) {
  return m.recursive.head != s or m.recursive.tail != s;
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr bool operator!=(const tmat<T, N, M>& m, U s) {
  return m != static_cast<T>(s);
}
template <typename T, size_t N, size_t M, typename>
constexpr bool operator!=(const tmat<T, N, M>& m, const tmat<T, N, M>& n) {
  return m.recursive.head != n.recursive.head or m.recursive.tail !=
         n.recursive.tail;
}
