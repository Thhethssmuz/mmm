#ifndef mmm_mat_func_io_hpp
#define mmm_mat_func_io_hpp

// prints matrix to stdout in row-major order
template <typename T, size_t N, size_t M>
void print(const tmat<T, N, M>& m);

#endif