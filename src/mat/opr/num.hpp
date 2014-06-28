#ifndef mmm_mat_tmat_opr_num_hpp
#define mmm_mat_tmat_opr_num_hpp

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, N, M> operator*(T s, const tmat<T, N, M>& m);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr tmat<T, N, M> operator*(U s, const tmat<T, N, M>& m);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, N, M> operator*(const tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr tmat<T, N, M> operator*(const tmat<T, N, M>& m, U s);


template <typename T, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, 2> operator*(const tvec<T, M>& v, const tmat<T, 2, M>& m);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator*(const tvec<T, M>& v, const tmat<T, N, M>& m);

template <typename T, size_t N, size_t M, typename A,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> operator*(const vecType<T, M, A>& v,
                               const tmat<T, N, M>& m);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, 2> operator*(const tmat<T, N, 2>& m, const tvec<T, N>& v);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, M> operator*(const tmat<T, N, M>& m, const tvec<T, N>& v);

template <typename T, size_t N, size_t M, typename A,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, M> operator*(const tmat<T, N, M>& m,
                               const vecType<T, N, A>& v);


template <typename T, size_t N, size_t M, size_t O,
          typename = typefu::for_arithmetic<T>>
constexpr tmat<T, O, M> operator*(const tmat<T, N, M>& m,
                                  const tmat<T, O, N>& n);

#endif