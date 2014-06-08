#ifndef mmm_vec_opr_asig_hpp
#define mmm_vec_opr_asig_hpp

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator+=(tvec<T, n>& v, T s);

template <typename T, typename U, size_t n,
          typename = typefu::for_arithmetic<T, U>>
tvec<T, n>& operator+=(tvec<T, n>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator+=(tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A,
          typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator+=(tvec<T, n>& v, const vecType<T, n, A>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator-=(tvec<T, n>& v, T s);

template <typename T, typename U, size_t n,
          typename = typefu::for_arithmetic<T, U>>
tvec<T, n>& operator-=(tvec<T, n>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator-=(tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A,
          typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator-=(tvec<T, n>& v, const vecType<T, n, A>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator*=(tvec<T, n>& v, T s);

template <typename T, typename U, size_t n,
          typename = typefu::for_arithmetic<T, U>>
tvec<T, n>& operator*=(tvec<T, n>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator*=(tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A,
          typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator*=(tvec<T, n>& v, const vecType<T, n, A>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator/=(tvec<T, n>& v, T s);

template <typename T, typename U, size_t n,
          typename = typefu::for_arithmetic<T, U>>
tvec<T, n>& operator/=(tvec<T, n>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator/=(tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A,
          typename = typefu::for_arithmetic<T>>
tvec<T, n>& operator/=(tvec<T, n>& v, const vecType<T, n, A>& u);

#endif