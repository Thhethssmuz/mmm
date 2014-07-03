#ifndef mmm_mat_opr_asig_hpp
#define mmm_mat_opr_asig_hpp

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
tmat<T, N, M>& operator+=(tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
tmat<T, N, M>& operator+=(tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
tmat<T, N, M>& operator+=(tmat<T, N, M>& m, const tmat<T, N, M>& n);


template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
tmat<T, N, M>& operator-=(tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
tmat<T, N, M>& operator-=(tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
tmat<T, N, M>& operator-=(tmat<T, N, M>& m, const tmat<T, N, M>& n);


template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
tmat<T, N, M>& operator*=(tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
tmat<T, N, M>& operator*=(tmat<T, N, M>& m, U s);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tmat<T, N, N>& operator*=(tmat<T, N, N>& m, const tmat<T, N, N>& n);


template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
tmat<T, N, M>& operator/=(tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
tmat<T, N, M>& operator/=(tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
tmat<T, N, M>& operator/=(tmat<T, N, M>& m, const tmat<T, N, M>& n);

#endif