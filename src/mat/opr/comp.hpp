#ifndef mmm_mat_opr_comp_hpp
#define mmm_mat_opr_comp_hpp

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator>(T s, const tmat<T, N, M>& m);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator>(U s, const tmat<T, N, M>& m);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator>(const tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator>(const tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator>(const tmat<T, N, M>& m, const tmat<T, N, M>& n);


template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator>=(T s, const tmat<T, N, M>& m);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator>=(U s, const tmat<T, N, M>& m);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator>=(const tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator>=(const tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator>=(const tmat<T, N, M>& m, const tmat<T, N, M>& n);


template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator<=(T s, const tmat<T, N, M>& m);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator<=(U s, const tmat<T, N, M>& m);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator<=(const tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator<=(const tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator<=(const tmat<T, N, M>& m, const tmat<T, N, M>& n);


template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator<(T s, const tmat<T, N, M>& m);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator<(U s, const tmat<T, N, M>& m);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator<(const tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator<(const tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator<(const tmat<T, N, M>& m, const tmat<T, N, M>& n);


template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator==(T s, const tmat<T, N, M>& m);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator==(U s, const tmat<T, N, M>& m);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator==(const tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator==(const tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator==(const tmat<T, N, M>& m, const tmat<T, N, M>& n);


template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator!=(T s, const tmat<T, N, M>& m);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator!=(U s, const tmat<T, N, M>& m);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator!=(const tmat<T, N, M>& m, T s);

template <typename T, typename U, size_t N, size_t M,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator!=(const tmat<T, N, M>& m, U s);

template <typename T, size_t N, size_t M, typename = typefu::for_arithmetic<T>>
constexpr bool operator!=(const tmat<T, N, M>& m, const tmat<T, N, M>& n);

#endif