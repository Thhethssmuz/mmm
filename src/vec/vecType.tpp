#ifndef mmm_vec_vectype_tpp
#define mmm_vec_vectype_tpp

template <typename T, size_t n, typename A>
constexpr tvec<T, n> vec_cast(const vecType<T, n, A>& v) {
  return static_cast<tvec<T, n>>(static_cast<const A&>(v));
}

template <typename T, size_t n>
constexpr tvec<T, n> vec_cast(const vecType<T, n, tvec<T, n>>& v) {
  return static_cast<const tvec<T, n>&>(v);
}

#endif