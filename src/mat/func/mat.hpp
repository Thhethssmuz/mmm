#ifndef mmm_mat_func_mat_hpp
#define mmm_mat_func_mat_hpp

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, N, M> matrixCompMult(const tmat<T, N, M>& m,
                                       const tmat<T, N, M>& n);

template <typename T, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, 2, M> matrixCompMult(const tmat<T, 2, M>& m,
                                       const tmat<T, 2, M>& n);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> outerProduct(T c, const tvec<T, N>& r);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> outerProduct(U c, const vecType<T, N, A>& r);

template <typename T, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, M> outerProduct(const tvec<T, M>& c, T r);

template <typename T, typename U, size_t M, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, M> outerProduct(const vecType<T, M, A>& c, U r);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, N, M> outerProduct(const tvec<T, M>& c, const tvec<T, N>& r);

template <typename T, size_t N, size_t M, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tmat<T, N, M> outerProduct(const vecType<T, M, A>& c,
                                     const vecType<T, N, B>& r);


template <typename T, size_t N, size_t M>
constexpr tmat<T, M, N> transpose(const tmat<T, N, M>& m);

template <typename T, size_t N>
constexpr tvec<T, N> transpose(const tvec<T, N>& v);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T determinant(const tmat<T, 2, 2>& m);


#endif