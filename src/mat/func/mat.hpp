#pragma once

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, N, M> matrixCompMult(const tmat<T, N, M>& m,
                                       const tmat<T, N, M>& n);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tmat<T, N, 2> matrixCompMult(const tmat<T, N, 2>& m,
                                       const tmat<T, N, 2>& n);


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


template <typename T, typename = typefu::for_signed<T>>
constexpr T determinant(const tmat<T, 2, 2>& m);

template <size_t L = 0, typename T, size_t N, typename = typefu::for_signed<T>,
          typename = typefu::for_<(L < N - 1)>, typename = void>
constexpr T determinant(const tmat<T, N, N>& m);

template <size_t L, typename T, size_t N, typename = typefu::for_signed<T>,
          typename = typefu::for_<(L == N - 1)>>
constexpr T determinant(const tmat<T, N, N>& m);


template <size_t R, size_t C, typename T, typename = typefu::for_signed<T>,
          typename = typefu::for_<(R < 2 and C < 2)>>
constexpr T cofactor(const tmat<T, 2, 2>& m);

template <size_t R, size_t C, typename T, size_t N,
          typename = typefu::for_signed<T>,
          typename = typefu::for_<(R < N and C < N)>>
constexpr T cofactor(const tmat<T, N, N>& m);


template <typename T, typename = typefu::for_signed<T>>
constexpr tmat<T, 2, 2> cofactors(const tmat<T, 2, 2>& m);

template <size_t R = 0, typename T, size_t N, typename = typefu::for_signed<T>,
          typename = typefu::for_<(N - R > 2)>, typename = void>
constexpr tmat<T, N, N - R> cofactors(const tmat<T, N, N>& m);

template <size_t R, typename T, size_t N, typename = typefu::for_signed<T>,
          typename = typefu::for_<(N - R == 2)>>
constexpr tmat<T, N, 2> cofactors(const tmat<T, N, N>& m);

template <size_t R, size_t C, typename T, size_t N,
          typename = typefu::for_signed<T>,
          typename = typefu::for_<(N - C > 2)>, typename = void>
constexpr tvec<T, N - C> cofactors(const tmat<T, N, N>& m);

template <size_t R, size_t C, typename T, size_t N,
          typename = typefu::for_signed<T>,
          typename = typefu::for_<(N - C == 2)>>
constexpr tvec<T, 2> cofactors(const tmat<T, N, N>& m);


template <typename T, size_t N, typename = typefu::for_signed<T>>
constexpr tmat<T, N, N> adjugate(const tmat<T, N, N>& m);


template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tmat<T, N, N> inverse(const tmat<T, N, N>& m);
