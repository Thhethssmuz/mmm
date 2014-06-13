#ifndef mmm_vec_vectype_tpp
#define mmm_vec_vectype_tpp

template <typename T, size_t N, typename A>
constexpr tvec<T, N> vec_cast(const vecType<T, N, A>& v) {
  return static_cast<tvec<T, N>>(static_cast<const A&>(v));
}

template <typename T, size_t N>
constexpr tvec<T, N> vec_cast(const vecType<T, N, tvec<T, N>>& v) {
  return static_cast<const tvec<T, N>&>(v);
}

#endif