#ifndef mmm_vec_opr_enum_tpp
#define mmm_vec_opr_enum_tpp

template <typename T, size_t n, typename>
tvec<T, n>& operator++(tvec<T,n>& v) {
  v.recursive.head++;
  v.recursive.tail++;
  return v;
}
template <typename T, size_t n, typename>
tvec<T, n> operator++(tvec<T,n>& v, int) {
  tvec<T, n> tmp = v;
  v.recursive.head++;
  v.recursive.tail++;
  return tmp;
}

template <typename T, size_t n, typename>
tvec<T, n>& operator--(tvec<T,n>& v) {
  v.recursive.head--;
  v.recursive.tail--;
  return v;
}
template <typename T, size_t n, typename>
tvec<T, n> operator--(tvec<T,n>& v, int) {
  tvec<T, n> tmp = v;
  v.recursive.head--;
  v.recursive.tail--;
  return tmp;
}

#endif