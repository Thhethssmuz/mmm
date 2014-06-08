#ifndef mmm_vec_opr_io_hpp
#define mmm_vec_opr_io_hpp

template <typename T, size_t n, typename A>
std::ostream& operator<< (std::ostream& os, const vecType<T,n,A>& v);

template <typename T, size_t n>
std::ostream& operator<< (std::ostream& os, const tvec<T,n>& v);

#endif