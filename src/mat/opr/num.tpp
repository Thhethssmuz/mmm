#ifndef mmm_mat_tmat_opr_num_tpp
#define mmm_mat_tmat_opr_num_tpp

template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator+(T s, const tmat<T, N, M>& m) {
  return tmat<T, N, M>(s + m.recursive.head, s + m.recursive.tail);
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator+(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) + m;
}
template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator+(const tmat<T, N, M>& m, T s) {
  return tmat<T, N, M>(m.recursive.head + s, m.recursive.tail + s);
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator+(const tmat<T, N, M>& m, U s) {
  return m + static_cast<T>(s);
}


template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator+(const tmat<T, N, M>& m,
                                  const tmat<T, N, M>& n) {
  return tmat<T, N, M>(m.recursive.head + n.recursive.head,
                       m.recursive.tail + n.recursive.tail);
}


template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator-(T s, const tmat<T, N, M>& m) {
  return tmat<T, N, M>(s - m.recursive.head, s - m.recursive.tail);
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator-(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) - m;
}
template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator-(const tmat<T, N, M>& m, T s) {
  return tmat<T, N, M>(m.recursive.head - s, m.recursive.tail - s);
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator-(const tmat<T, N, M>& m, U s) {
  return m - static_cast<T>(s);
}


template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator-(const tmat<T, N, M>& m) {
  return tmat<T, N, M>(-m.recursive.head, -m.recursive.tail);
}
template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator-(const tmat<T, N, M>& m,
                                  const tmat<T, N, M>& n) {
  return tmat<T, N, M>(m.recursive.head - n.recursive.head,
                       m.recursive.tail - n.recursive.tail);
}


template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator*(T s, const tmat<T, N, M>& m) {
  return tmat<T, N, M>(s * m.recursive.head, s * m.recursive.tail);
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator*(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) * m;
}
template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator*(const tmat<T, N, M>& m, T s) {
  return tmat<T, N, M>(m.recursive.head * s, m.recursive.tail * s);
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator*(const tmat<T, N, M>& m, U s) {
  return m * static_cast<T>(s);
}


template <typename T, size_t M, typename>
constexpr tvec<T, 2> operator*(const tvec<T, M>& v, const tmat<T, 2, M>& m) {
  return tvec<T, 2>(dot(v, m.recursive.head), dot(v, m.recursive.tail));
}
template <typename T, size_t N, size_t M, typename>
constexpr tvec<T, N> operator*(const tvec<T, M>& v, const tmat<T, N, M>& m) {
  return tvec<T, N>(dot(v, m.recursive.head), v * m.recursive.tail);
}
template <typename T, size_t N, size_t M, typename A, typename>
constexpr tvec<T, N> operator*(const vecType<T, M, A>& v,
                               const tmat<T, N, M>& m) {
  return vec_cast(v) * m;
}


template <typename T, size_t N, typename>
constexpr tvec<T, 2> operator*(const tmat<T, N, 2>& m, const tvec<T, N>& v) {
  return tvec<T, 2>(dot(takeRows<1>(m), v), dot(dropRows<1>(m), v));
}
template <typename T, size_t N, size_t M, typename>
constexpr tvec<T, M> operator*(const tmat<T, N, M>& m, const tvec<T, N>& v) {
  return tvec<T, M>(dot(takeRows<1>(m), v), dropRows<1>(m) * v);
}
template <typename T, size_t N, size_t M, typename A, typename>
constexpr tvec<T, M> operator*(const tmat<T, N, M>& m,
                               const vecType<T, N, A>& v) {
  return m * vec_cast(v);
}


template <typename T, size_t N, size_t M, size_t O, typename>
constexpr tmat<T, O, M> operator*(const tmat<T, N, M>& m,
                                  const tmat<T, O, N>& n) {
  return tmat<T, O, M>(m * n.recursive.head, m * n.recursive.tail);
}


template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator/(T s, const tmat<T, N, M>& m) {
  return tmat<T, N, M>(s / m.recursive.head, s / m.recursive.tail);
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator/(U s, const tmat<T, N, M>& m) {
  return static_cast<T>(s) / m;
}
template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator/(const tmat<T, N, M>& m, T s) {
  return tmat<T, N, M>(m.recursive.head / s, m.recursive.tail / s);
}
template <typename T, typename U, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator/(const tmat<T, N, M>& m, U s) {
  return m / static_cast<T>(s);
}


template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> operator/(const tmat<T, N, M>& m,
                                  const tmat<T, N, M>& n) {
  return tmat<T, N, M>(m.recursive.head / n.recursive.head,
                       m.recursive.tail / n.recursive.tail);
}


#endif