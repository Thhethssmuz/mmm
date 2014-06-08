#ifndef mmm_vec_opr_num_tpp
#define mmm_vec_opr_num_tpp

template <typename T, size_t n, typename>
constexpr tvec<T, n> operator+(T s, const tvec<T, n>& v) {
  return tvec<T, n>(s + v.recursive.head, s + v.recursive.tail);
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<T, n> operator+(U s, const vecType<T, n, A>& v) {
  return static_cast<T>(s) + vec_cast(v);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator+(const tvec<T, n>& v, T s) {
  return tvec<T, n>(v.recursive.head + s, v.recursive.tail + s);
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<T, n> operator+(const vecType<T, n, A>& v, U s) {
  return vec_cast(v) + static_cast<T>(s);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator+(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<T, n>(v.recursive.head + u.recursive.head,
                    v.recursive.tail + u.recursive.tail);
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<T, n> operator+(const vecType<T, n, A>& v,
                               const vecType<T, n, B>& u) {
  return vec_cast(v) + vec_cast(u);
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> operator-(const tvec<T, n>& v) {
  return tvec<T, n>(-v.recursive.head, -v.recursive.tail);
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> operator-(const vecType<T, n, A>& v) {
  return -vec_cast(v);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator-(T s, const tvec<T, n>& v) {
  return tvec<T, n>(s - v.recursive.head, s - v.recursive.tail);
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<T, n> operator-(U s, const vecType<T, n, A>& v) {
  return static_cast<T>(s) - vec_cast(v);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator-(const tvec<T, n>& v, T s) {
  return tvec<T, n>(v.recursive.head - s, v.recursive.tail - s);
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<T, n> operator-(const vecType<T, n, A>& v, U s) {
  return vec_cast(v) - static_cast<T>(s);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator-(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<T, n>(v.recursive.head - u.recursive.head,
                    v.recursive.tail - u.recursive.tail);
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<T, n> operator-(const vecType<T, n, A>& v,
                               const vecType<T, n, B>& u) {
  return vec_cast(v) - vec_cast(u);
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> operator*(T s, const tvec<T, n>& v) {
  return tvec<T, n>(s * v.recursive.head, s * v.recursive.tail);
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<T, n> operator*(U s, const vecType<T, n, A>& v) {
  return static_cast<T>(s) * vec_cast(v);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator*(const tvec<T, n>& v, T s) {
  return tvec<T, n>(v.recursive.head * s, v.recursive.tail * s);
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<T, n> operator*(const vecType<T, n, A>& v, U s) {
  return vec_cast(v) * static_cast<T>(s);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator*(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<T, n>(v.recursive.head * u.recursive.head,
                    v.recursive.tail * u.recursive.tail);
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<T, n> operator*(const vecType<T, n, A>& v,
                               const vecType<T, n, B>& u) {
  return vec_cast(v) * vec_cast(u);
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> operator/(T s, const tvec<T, n>& v) {
  return tvec<T, n>(s / v.recursive.head, s / v.recursive.tail);
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<T, n> operator/(U s, const vecType<T, n, A>& v) {
  return static_cast<T>(s) / vec_cast(v);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator/(const tvec<T, n>& v, T s) {
  return tvec<T, n>(v.recursive.head / s, v.recursive.tail / s);
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<T, n> operator/(const vecType<T, n, A>& v, U s) {
  return vec_cast(v) / static_cast<T>(s);
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> operator/(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<T, n>(v.recursive.head / u.recursive.head,
                    v.recursive.tail / u.recursive.tail);
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<T, n> operator/(const vecType<T, n, A>& v,
                               const vecType<T, n, B>& u) {
  return vec_cast(v) / vec_cast(u);
}

#endif