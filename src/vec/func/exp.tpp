#pragma once

template <typename T, size_t N, typename>
constexpr tvec<T, N> pow(T s, const tvec<T, N>& v) {
  return tvec<T, N>(pow(s, v.recursive.head), pow(s, v.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename, typename>
constexpr tvec<T, N> pow(U s, const vecType<T, N, A>& v) {
  return pow(static_cast<T>(s), vec_cast(v));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> pow(const tvec<T, N>& v, T s) {
  return tvec<T, N>(pow(v.recursive.head, s), pow(v.recursive.tail, s));
}
template <typename T, typename U, size_t N, typename A, typename, typename>
constexpr tvec<T, N> pow(const vecType<T, N, A>& v, U s) {
  return pow(vec_cast(v), static_cast<T>(s));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> pow(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<T, N>(pow(v.recursive.head, u.recursive.head),
                    pow(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> pow(const vecType<T, N, A>& v, const vecType<T, N, B>& u) {
  return pow(vec_cast(v), vec_cast(u));
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> exp(const tvec<T, N>& x) {
  return tvec<T, N>(exp(x.recursive.head), exp(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> exp(const vecType<T, N, A>& x) {
  return exp(vec_cast(x));
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> log(const tvec<T, N>& x) {
  return tvec<T, N>(log(x.recursive.head), log(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> log(const vecType<T, N, A>& x) {
  return log(vec_cast(x));
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> exp2(const tvec<T, N>& x) {
  return tvec<T, N>(exp2(x.recursive.head), exp2(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> exp2(const vecType<T, N, A>& x) {
  return exp2(vec_cast(x));
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> log2(const tvec<T, N>& x) {
  return tvec<T, N>(log2(x.recursive.head), log2(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> log2(const vecType<T, N, A>& x) {
  return log2(vec_cast(x));
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> sqrt(const tvec<T, N>& x) {
  return tvec<T, N>(sqrt(x.recursive.head), sqrt(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> sqrt(const vecType<T, N, A>& x) {
  return sqrt(vec_cast(x));
}


template <typename T, typename>
constexpr typefu::promotef<T> inversesqrt(T x) {
  typedef typefu::promotef<T> type;
  return type(1) / sqrt(x);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> inversesqrt(const tvec<T, N>& x) {
  return tvec<T, N>(inversesqrt(x.recursive.head),
                    inversesqrt(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> inversesqrt(const vecType<T, N, A>& x) {
  return inversesqrt(vec_cast(x));
}
