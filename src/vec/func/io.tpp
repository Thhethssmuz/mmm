#ifndef mmm_vec_func_io_tpp
#define mmm_vec_func_io_tpp

template <typename T, size_t N>
void print(const tvec<T, N>& v) {
  std::cout << "[" << v.data[0];
  for (size_t i = 1; i < N; ++i)
    std::cout << ", " << v.data[i];
  std::cout << "]" << std::endl;
}

template <typename T, size_t N, typename A>
void print(const vecType<T, N, A>& v) {
  print(vec_cast(v));
}

#endif