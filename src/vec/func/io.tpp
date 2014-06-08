#ifndef mmm_vec_func_io_tpp
#define mmm_vec_func_io_tpp

template <typename T, size_t n>
void print(const tvec<T, n>& v) {
  std::cout << "[" << v.data[0];
  for (size_t i = 1; i < n; ++i)
    std::cout << ", " << v.data[i];
  std::cout << "]" << std::endl;
}

template <typename T, size_t n, typename A>
void print(const vecType<T, n, A>& v) {
  print(vec_cast(v));
}

#endif