#ifndef mmm_vec_func_exp_hpp
#define mmm_vec_func_exp_hpp

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> pow(T s, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, n> pow(U s, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> pow(const tvec<T, n>& v, T s);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, n> pow(const vecType<T, n, A>& v, U s);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> pow(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_floating<T>>
constexpr tvec<T, n> pow(const vecType<T, n, A>& v, const vecType<T, n, B>& u);


template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> exp(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> exp(const vecType<T, n, A>& x);


template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> log(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> log(const vecType<T, n, A>& x);


template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> exp2(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> exp2(const vecType<T, n, A>& x);


template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> log2(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> log2(const vecType<T, n, A>& x);


template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> sqrt(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> sqrt(const vecType<T, n, A>& x);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> inversesqrt(T x);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> inversesqrt(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> inversesqrt(const vecType<T, n, A>& x);

#endif