#ifndef mmm_vec_func_rel_hpp
#define mmm_vec_func_rel_hpp

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool lessThan(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool lessThan(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> lessThan(T x, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> lessThan(U x, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> lessThan(const tvec<T, n>& v, T x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> lessThan(const vecType<T, n, A>& v, U x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> lessThan(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> lessThan(const vecType<T, n, A>& v,
                                 const vecType<T, n, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool lessThanEqual(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool lessThanEqual(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> lessThanEqual(T x, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> lessThanEqual(U x, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> lessThanEqual(const tvec<T, n>& v, T x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> lessThanEqual(const vecType<T, n, A>& v, U x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> lessThanEqual(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> lessThanEqual(const vecType<T, n, A>& v,
                                      const vecType<T, n, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool greaterThan(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool greaterThan(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> greaterThan(T x, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> greaterThan(U x, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> greaterThan(const tvec<T, n>& v, T x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> greaterThan(const vecType<T, n, A>& v, U x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> greaterThan(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> greaterThan(const vecType<T, n, A>& v,
                                    const vecType<T, n, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool greaterThanEqual(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool greaterThanEqual(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> greaterThanEqual(T x, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> greaterThanEqual(U x, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> greaterThanEqual(const tvec<T, n>& v, T x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> greaterThanEqual(const vecType<T, n, A>& v, U x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> greaterThanEqual(const tvec<T, n>& v,
                                         const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> greaterThanEqual(const vecType<T, n, A>& v,
                                         const vecType<T, n, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool equal(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool equal(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> equal(T x, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> equal(U x, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> equal(const tvec<T, n>& v, T x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> equal(const vecType<T, n, A>& v, U x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> equal(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> equal(const vecType<T, n, A>& v,
                              const vecType<T, n, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr bool notEqual(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr bool notEqual(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> notEqual(T x, const tvec<T, n>& v);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> notEqual(U x, const vecType<T, n, A>& v);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> notEqual(const tvec<T, n>& v, T x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<bool, n> notEqual(const vecType<T, n, A>& v, U x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> notEqual(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<bool, n> notEqual(const vecType<T, n, A>& v,
                                 const vecType<T, n, B>& u);


constexpr bool any(bool x);

template <size_t n>
constexpr bool any(const tvec<bool, n>& v);

template <size_t n, typename A>
constexpr bool any(const vecType<bool, n, A>& v);


constexpr bool all(bool x);

template <size_t n>
constexpr bool all(const tvec<bool, n>& v);

template <size_t n, typename A>
constexpr bool all(const vecType<bool, n, A>& v);


template <size_t n>
constexpr tvec<bool, n> operator!(const tvec<bool, n> & v);

template <size_t n, typename A>
constexpr tvec<bool, n> operator!(const vecType<bool, n, A> & v);

#endif