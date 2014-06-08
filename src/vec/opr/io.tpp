#ifndef mmm_vec_opr_io_tpp
#define mmm_vec_opr_io_tpp

template <typename T, size_t n, typename A>
std::ostream& operator<< (std::ostream& os, const vecType<T,n,A>& v) {
  return os << vec_cast(v);
}

template <typename T, size_t n>
std::ostream& operator<< (std::ostream& os, const tvec<T,n>& v) {
  os << "[" << v.data[0];
  for (size_t i = 1; i < n; ++i)
    os << ", " << v.data[i];
  os << "]";
  return os;
}

#endif