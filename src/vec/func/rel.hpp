#ifndef mmm_vec_func_rel_hpp
#define mmm_vec_func_rel_hpp

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool lessThan(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool lessThan(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> lessThan(T x, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> lessThan(U x, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> lessThan(const tvec<T, N>& v, T x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> lessThan(const vecType<T, N, A>& v, U x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> lessThan(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> lessThan(const vecType<T, N, A>& v,
                                 const vecType<T, N, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool lessThanEqual(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool lessThanEqual(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> lessThanEqual(T x, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> lessThanEqual(U x, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> lessThanEqual(const tvec<T, N>& v, T x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> lessThanEqual(const vecType<T, N, A>& v, U x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> lessThanEqual(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> lessThanEqual(const vecType<T, N, A>& v,
                                      const vecType<T, N, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool greaterThan(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool greaterThan(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> greaterThan(T x, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> greaterThan(U x, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> greaterThan(const tvec<T, N>& v, T x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> greaterThan(const vecType<T, N, A>& v, U x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> greaterThan(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> greaterThan(const vecType<T, N, A>& v,
                                    const vecType<T, N, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool greaterThanEqual(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool greaterThanEqual(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> greaterThanEqual(T x, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> greaterThanEqual(U x, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> greaterThanEqual(const tvec<T, N>& v, T x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> greaterThanEqual(const vecType<T, N, A>& v, U x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> greaterThanEqual(const tvec<T, N>& v,
                                         const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> greaterThanEqual(const vecType<T, N, A>& v,
                                         const vecType<T, N, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool equal(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool equal(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> equal(T x, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> equal(U x, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> equal(const tvec<T, N>& v, T x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> equal(const vecType<T, N, A>& v, U x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> equal(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> equal(const vecType<T, N, A>& v,
                              const vecType<T, N, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool notEqual(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool notEqual(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> notEqual(T x, const tvec<T, N>& v);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> notEqual(U x, const vecType<T, N, A>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> notEqual(const tvec<T, N>& v, T x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, N> notEqual(const vecType<T, N, A>& v, U x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> notEqual(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, N> notEqual(const vecType<T, N, A>& v,
                                 const vecType<T, N, B>& u);


constexpr bool any(bool x);

template <size_t N>
constexpr bool any(const tvec<bool, N>& v);

template <size_t N, typename A>
constexpr bool any(const vecType<bool, N, A>& v);


constexpr bool all(bool x);

template <size_t N>
constexpr bool all(const tvec<bool, N>& v);

template <size_t N, typename A>
constexpr bool all(const vecType<bool, N, A>& v);


template <size_t N>
constexpr tvec<bool, N> operator!(const tvec<bool, N> & v);

template <size_t N, typename A>
constexpr tvec<bool, N> operator!(const vecType<bool, N, A> & v);

#endif