#ifndef mmm_vec_opr_num_hpp
#define mmm_vec_opr_num_hpp

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator+(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> operator+(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator+(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> operator+(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator+(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator+(const vecType<T, n, A>& v,
                               const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator-(const tvec<T, n>& v);

template <typename T, size_t n, typename A,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator-(const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator-(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> operator-(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator-(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> operator-(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator-(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator-(const vecType<T, n, A>& v,
                               const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator*(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> operator*(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator*(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> operator*(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator*(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator*(const vecType<T, n, A>& v,
                               const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator/(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> operator/(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator/(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> operator/(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator/(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> operator/(const vecType<T, n, A>& v,
                               const vecType<T, n, B>& u);

#endif