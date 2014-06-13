#ifndef mmm_vec_func_reduct_tpp
#define mmm_vec_func_reduct_tpp

template <typename T, size_t N>
constexpr T sum(const tvec<T, N>& v) {
  return v.recursive.head + sum(v.recursive.tail);
}
template <typename T>
constexpr T sum(const tvec<T, 2>& v) {
  return v.recursive.head + v.recursive.tail;
}
template <typename T, size_t N, typename A>
constexpr T sum(const vecType<T, N, A>& v) {
  return sum(vec_cast(v));
}


template <typename T, size_t N>
constexpr T product(const tvec<T, N>& v) {
  return v.recursive.head * product(v.recursive.tail);
}
template <typename T>
constexpr T product(const tvec<T, 2>& v) {
  return v.recursive.head * v.recursive.tail;
}
template <typename T, size_t N, typename A>
constexpr T product(const vecType<T, N, A>& v) {
  return product(vec_cast(v));
}


template <size_t N, typename T, size_t L, typename, typename>
constexpr tvec<T, N> take(const tvec<T, L>& v) {
  return tvec<T, N>(v.recursive.head, take<N - 1>(v.recursive.tail));
}
template <size_t N, typename T, size_t L, typename A, typename, typename>
constexpr tvec<T, N> take(const vecType<T, L, A>& v) {
  return take<N>(vec_cast(v));
}
template <size_t N, typename T, size_t L, typename>
constexpr T take(const tvec<T, L>& v) {
  return v.recursive.head;
}
template <size_t N, typename T, size_t L, typename A, typename>
constexpr T take(const vecType<T, L, A>& v) {
  return take<1>(vec_cast(v));
}
template <size_t N, typename T, typename>
constexpr T take(T x) {
  return x;
}


template <size_t N, typename T, size_t L, typename>
constexpr tvec<T, L - N> drop(const tvec<T, L>& v) {
  return drop<N - 1>(v.recursive.tail);
}
template <size_t N, typename T, size_t L, typename, typename>
constexpr tvec<T, L - N> drop(const tvec<T, L>& v) {
  return v;
}
template <size_t N, typename T, size_t L, typename A, typename>
constexpr tvec<T, L - N> drop(const vecType<T, L, A>& v) {
  return drop<N>(vec_cast(v));
}
template <size_t N, typename T, size_t L, typename>
constexpr T drop(const tvec<T, L>& v) {
  return v[L-1];
}
template <size_t N, typename T, size_t L, typename A, typename>
constexpr T drop(const vecType<T, L, A>& v) {
  return drop<N>(vec_cast(v));
}

#endif