#ifndef mmm_vec_func_io_hpp
#define mmm_vec_func_io_hpp

template <typename T, size_t n>
void print(const tvec<T, n>& v);

template <typename T, size_t n, typename A>
void print(const vecType<T, n, A>& v);

#endif