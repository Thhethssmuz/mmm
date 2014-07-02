#ifndef mmm_mat_opr_io_hpp
#define mmm_mat_opr_io_hpp

template <typename T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& os, const tmat<T, N, M>& m);

#endif