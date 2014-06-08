#ifndef mmm_vec_opr_comp_hpp
#define mmm_vec_opr_comp_hpp

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator<(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator<(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator<(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator<(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator<(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr bool operator<(const vecType<T, n, A>& v, const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator<=(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator<=(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator<=(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator<=(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator<=(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr bool operator<=(const vecType<T, n, A>& v, const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator>=(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator>=(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator>=(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator>=(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator>=(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr bool operator>=(const vecType<T, n, A>& v, const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator>(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator>(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator>(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator>(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator>(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr bool operator>(const vecType<T, n, A>& v, const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator==(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator==(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator==(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator==(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator==(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr bool operator==(const vecType<T, n, A>& v, const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator!=(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator!=(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator!=(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr bool operator!=(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr bool operator!=(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr bool operator!=(const vecType<T, n, A>& v, const vecType<T, n, B>& u);

#endif