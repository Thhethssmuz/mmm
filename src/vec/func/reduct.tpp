#ifndef mmm_vec_func_reduct_tpp
#define mmm_vec_func_reduct_tpp

template <typename T, size_t n>
constexpr T sum(const tvec<T, n>& v) {
  return v.recursive.head + sum(v.recursive.tail);
}
template <typename T>
constexpr T sum(const tvec<T, 2>& v) {
  return v.recursive.head + v.recursive.tail;
}
template <typename T, size_t n, typename A>
constexpr T sum(const vecType<T, n, A>& v) {
  return sum(vec_cast(v));
}


template <typename T, size_t n>
constexpr T product(const tvec<T, n>& v) {
  return v.recursive.head * product(v.recursive.tail);
}
template <typename T>
constexpr T product(const tvec<T, 2>& v) {
  return v.recursive.head * v.recursive.tail;
}
template <typename T, size_t n, typename A>
constexpr T product(const vecType<T, n, A>& v) {
  return product(vec_cast(v));
}

#endif