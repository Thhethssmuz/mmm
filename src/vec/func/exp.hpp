#ifndef mmm_vec_func_exp_hpp
#define mmm_vec_func_exp_hpp

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> pow(T s, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, N> pow(U s, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> pow(const tvec<T, N>& v, T s);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, N> pow(const vecType<T, N, A>& v, U s);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> pow(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_floating<T>>
constexpr tvec<T, N> pow(const vecType<T, N, A>& v, const vecType<T, N, B>& u);


template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> exp(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> exp(const vecType<T, N, A>& x);


template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> log(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> log(const vecType<T, N, A>& x);


template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> exp2(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> exp2(const vecType<T, N, A>& x);


template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> log2(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> log2(const vecType<T, N, A>& x);


template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> sqrt(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> sqrt(const vecType<T, N, A>& x);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> inversesqrt(T x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> inversesqrt(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> inversesqrt(const vecType<T, N, A>& x);

#endif