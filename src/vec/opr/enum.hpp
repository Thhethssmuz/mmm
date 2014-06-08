#ifndef mmm_vec_opr_enum_hpp
#define mmm_vec_opr_enum_hpp

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator++(tvec<T,n>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n> operator++(tvec<T,n>& v, int);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator--(tvec<T,n>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n> operator--(tvec<T,n>& v, int);

#endif