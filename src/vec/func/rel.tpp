#ifndef mmm_vec_func_rel_tpp
#define mmm_vec_func_rel_tpp

template <typename T, typename>
constexpr bool lessThan(T x, T y) {
  return x < y;
}
template <typename T, typename U, typename>
constexpr bool lessThan(T x, U y) {
  typedef typefu::promote<T, U> type;
  return lessThan(type(x), type(y));
}

template <typename T, size_t n, typename>
constexpr tvec<bool, n> lessThan(T x, const tvec<T, n>& v) {
  return tvec<bool, n>(lessThan(x, v.recursive.head),
                       lessThan(x, v.recursive.tail));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> lessThan(U x, const vecType<T, n, A>& v) {
  return lessThan(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> lessThan(const tvec<T, n>& v, T x) {
  return tvec<bool, n>(lessThan(v.recursive.head, x),
                       lessThan(v.recursive.tail, x));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> lessThan(const vecType<T, n, A>& v, U x) {
  return lessThan(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> lessThan(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<bool, n>(lessThan(v.recursive.head, u.recursive.head),
                       lessThan(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<bool, n> lessThan(const vecType<T, n, A>& v,
                                 const vecType<T, n, B>& u) {
  return lessThan(vec_cast(v), vec_cast(u));
}


template <typename T, typename>
constexpr bool lessThanEqual(T x, T y) {
  return x <= y;
}
template <typename T, typename U, typename>
constexpr bool lessThanEqual(T x, U y) {
  typedef typefu::promote<T, U> type;
  return lessThanEqual(type(x), type(y));
}

template <typename T, size_t n, typename>
constexpr tvec<bool, n> lessThanEqual(T x, const tvec<T, n>& v) {
  return tvec<bool, n>(lessThanEqual(x, v.recursive.head),
                       lessThanEqual(x, v.recursive.tail));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> lessThanEqual(U x, const vecType<T, n, A>& v) {
  return lessThanEqual(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> lessThanEqual(const tvec<T, n>& v, T x) {
  return tvec<bool, n>(lessThanEqual(v.recursive.head, x),
                       lessThanEqual(v.recursive.tail, x));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> lessThanEqual(const vecType<T, n, A>& v, U x) {
  return lessThanEqual(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> lessThanEqual(const tvec<T, n>& v,
                                      const tvec<T, n>& u) {
  return tvec<bool, n>(lessThanEqual(v.recursive.head, u.recursive.head),
                       lessThanEqual(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<bool, n> lessThanEqual(const vecType<T, n, A>& v,
                                      const vecType<T, n, B>& u) {
  return lessThanEqual(vec_cast(v), vec_cast(u));
}


template <typename T, typename>
constexpr bool greaterThan(T x, T y) {
  return x > y;
}
template <typename T, typename U, typename>
constexpr bool greaterThan(T x, U y) {
  typedef typefu::promote<T, U> type;
  return greaterThan(type(x), type(y));
}

template <typename T, size_t n, typename>
constexpr tvec<bool, n> greaterThan(T x, const tvec<T, n>& v) {
  return tvec<bool, n>(greaterThan(x, v.recursive.head),
                       greaterThan(x, v.recursive.tail));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> greaterThan(U x, const vecType<T, n, A>& v) {
  return greaterThan(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> greaterThan(const tvec<T, n>& v, T x) {
  return tvec<bool, n>(greaterThan(v.recursive.head, x),
                       greaterThan(v.recursive.tail, x));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> greaterThan(const vecType<T, n, A>& v, U x) {
  return greaterThan(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> greaterThan(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<bool, n>(greaterThan(v.recursive.head, u.recursive.head),
                       greaterThan(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<bool, n> greaterThan(const vecType<T, n, A>& v,
                                    const vecType<T, n, B>& u) {
  return greaterThan(vec_cast(v), vec_cast(u));
}


template <typename T, typename>
constexpr bool greaterThanEqual(T x, T y) {
  return x >= y;
}
template <typename T, typename U, typename>
constexpr bool greaterThanEqual(T x, U y) {
  typedef typefu::promote<T, U> type;
  return greaterThanEqual(type(x), type(y));
}

template <typename T, size_t n, typename>
constexpr tvec<bool, n> greaterThanEqual(T x, const tvec<T, n>& v) {
  return tvec<bool, n>(greaterThanEqual(x, v.recursive.head),
                       greaterThanEqual(x, v.recursive.tail));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> greaterThanEqual(U x, const vecType<T, n, A>& v) {
  return greaterThanEqual(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> greaterThanEqual(const tvec<T, n>& v, T x) {
  return tvec<bool, n>(greaterThanEqual(v.recursive.head, x),
                       greaterThanEqual(v.recursive.tail, x));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> greaterThanEqual(const vecType<T, n, A>& v, U x) {
  return greaterThanEqual(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> greaterThanEqual(const tvec<T, n>& v,
                                         const tvec<T, n>& u) {
  return tvec<bool, n>(greaterThanEqual(v.recursive.head, u.recursive.head),
                       greaterThanEqual(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<bool, n> greaterThanEqual(const vecType<T, n, A>& v,
                                         const vecType<T, n, B>& u) {
  return greaterThanEqual(vec_cast(v), vec_cast(u));
}


template <typename T, typename>
constexpr bool equal(T x, T y) {
  return x == y;
}
template <typename T, typename U, typename>
constexpr bool equal(T x, U y) {
  typedef typefu::promote<T, U> type;
  return equal(type(x), type(y));
}

template <typename T, size_t n, typename>
constexpr tvec<bool, n> equal(T x, const tvec<T, n>& v) {
  return tvec<bool, n>(equal(x, v.recursive.head), equal(x, v.recursive.tail));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> equal(U x, const vecType<T, n, A>& v) {
  return equal(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> equal(const tvec<T, n>& v, T x) {
  return tvec<bool, n>(equal(v.recursive.head, x), equal(v.recursive.tail, x));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> equal(const vecType<T, n, A>& v, U x) {
  return equal(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> equal(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<bool, n>(equal(v.recursive.head, u.recursive.head),
                       equal(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<bool, n> equal(const vecType<T, n, A>& v,
                              const vecType<T, n, B>& u) {
  return equal(vec_cast(v), vec_cast(u));
}


template <typename T, typename>
constexpr bool notEqual(T x, T y) {
  return x != y;
}
template <typename T, typename U, typename>
constexpr bool notEqual(T x, U y) {
  typedef typefu::promote<T, U> type;
  return notEqual(type(x), type(y));
}

template <typename T, size_t n, typename>
constexpr tvec<bool, n> notEqual(T x, const tvec<T, n>& v) {
  return tvec<bool, n>(notEqual(x, v.recursive.head),
                       notEqual(x, v.recursive.tail));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> notEqual(U x, const vecType<T, n, A>& v) {
  return notEqual(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> notEqual(const tvec<T, n>& v, T x) {
  return tvec<bool, n>(notEqual(v.recursive.head, x),
                       notEqual(v.recursive.tail, x));
}
template <typename T, typename U, size_t n, typename A, typename>
constexpr tvec<bool, n> notEqual(const vecType<T, n, A>& v, U x) {
  return notEqual(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t n, typename>
constexpr tvec<bool, n> notEqual(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<bool, n>(notEqual(v.recursive.head, u.recursive.head),
                       notEqual(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<bool, n> notEqual(const vecType<T, n, A>& v,
                                 const vecType<T, n, B>& u) {
  return notEqual(vec_cast(v), vec_cast(u));
}


constexpr bool any(bool x) { return x; }

template <size_t n>
constexpr bool any(const tvec<bool, n>& v) {
  return v.recursive.head or any(v.recursive.tail);
}
template <size_t n, typename A>
constexpr bool any(const vecType<bool, n, A>& v) {
  return any(vec_cast(v));
}


constexpr bool all(bool x) { return x; }

template <size_t n>
constexpr bool all(const tvec<bool, n>& v) {
  return v.recursive.head and all(v.recursive.tail);
}
template <size_t n, typename A>
constexpr bool all(const vecType<bool, n, A>& v) {
  return all(vec_cast(v));
}


template <size_t n>
constexpr tvec<bool, n> operator!(const tvec<bool, n> & v) {
  return tvec<bool, n>(not v.recursive.head, not v.recursive.tail);
}
template <size_t n, typename A>
constexpr tvec<bool, n> operator!(const vecType<bool, n, A> & v) {
  return not vec_cast(v);
}

#endif