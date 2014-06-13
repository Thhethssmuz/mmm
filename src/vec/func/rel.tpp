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

template <typename T, size_t N, typename>
constexpr tvec<bool, N> lessThan(T x, const tvec<T, N>& v) {
  return tvec<bool, N>(lessThan(x, v.recursive.head),
                       lessThan(x, v.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> lessThan(U x, const vecType<T, N, A>& v) {
  return lessThan(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> lessThan(const tvec<T, N>& v, T x) {
  return tvec<bool, N>(lessThan(v.recursive.head, x),
                       lessThan(v.recursive.tail, x));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> lessThan(const vecType<T, N, A>& v, U x) {
  return lessThan(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> lessThan(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<bool, N>(lessThan(v.recursive.head, u.recursive.head),
                       lessThan(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<bool, N> lessThan(const vecType<T, N, A>& v,
                                 const vecType<T, N, B>& u) {
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

template <typename T, size_t N, typename>
constexpr tvec<bool, N> lessThanEqual(T x, const tvec<T, N>& v) {
  return tvec<bool, N>(lessThanEqual(x, v.recursive.head),
                       lessThanEqual(x, v.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> lessThanEqual(U x, const vecType<T, N, A>& v) {
  return lessThanEqual(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> lessThanEqual(const tvec<T, N>& v, T x) {
  return tvec<bool, N>(lessThanEqual(v.recursive.head, x),
                       lessThanEqual(v.recursive.tail, x));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> lessThanEqual(const vecType<T, N, A>& v, U x) {
  return lessThanEqual(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> lessThanEqual(const tvec<T, N>& v,
                                      const tvec<T, N>& u) {
  return tvec<bool, N>(lessThanEqual(v.recursive.head, u.recursive.head),
                       lessThanEqual(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<bool, N> lessThanEqual(const vecType<T, N, A>& v,
                                      const vecType<T, N, B>& u) {
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

template <typename T, size_t N, typename>
constexpr tvec<bool, N> greaterThan(T x, const tvec<T, N>& v) {
  return tvec<bool, N>(greaterThan(x, v.recursive.head),
                       greaterThan(x, v.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> greaterThan(U x, const vecType<T, N, A>& v) {
  return greaterThan(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> greaterThan(const tvec<T, N>& v, T x) {
  return tvec<bool, N>(greaterThan(v.recursive.head, x),
                       greaterThan(v.recursive.tail, x));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> greaterThan(const vecType<T, N, A>& v, U x) {
  return greaterThan(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> greaterThan(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<bool, N>(greaterThan(v.recursive.head, u.recursive.head),
                       greaterThan(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<bool, N> greaterThan(const vecType<T, N, A>& v,
                                    const vecType<T, N, B>& u) {
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

template <typename T, size_t N, typename>
constexpr tvec<bool, N> greaterThanEqual(T x, const tvec<T, N>& v) {
  return tvec<bool, N>(greaterThanEqual(x, v.recursive.head),
                       greaterThanEqual(x, v.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> greaterThanEqual(U x, const vecType<T, N, A>& v) {
  return greaterThanEqual(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> greaterThanEqual(const tvec<T, N>& v, T x) {
  return tvec<bool, N>(greaterThanEqual(v.recursive.head, x),
                       greaterThanEqual(v.recursive.tail, x));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> greaterThanEqual(const vecType<T, N, A>& v, U x) {
  return greaterThanEqual(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> greaterThanEqual(const tvec<T, N>& v,
                                         const tvec<T, N>& u) {
  return tvec<bool, N>(greaterThanEqual(v.recursive.head, u.recursive.head),
                       greaterThanEqual(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<bool, N> greaterThanEqual(const vecType<T, N, A>& v,
                                         const vecType<T, N, B>& u) {
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

template <typename T, size_t N, typename>
constexpr tvec<bool, N> equal(T x, const tvec<T, N>& v) {
  return tvec<bool, N>(equal(x, v.recursive.head), equal(x, v.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> equal(U x, const vecType<T, N, A>& v) {
  return equal(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> equal(const tvec<T, N>& v, T x) {
  return tvec<bool, N>(equal(v.recursive.head, x), equal(v.recursive.tail, x));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> equal(const vecType<T, N, A>& v, U x) {
  return equal(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> equal(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<bool, N>(equal(v.recursive.head, u.recursive.head),
                       equal(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<bool, N> equal(const vecType<T, N, A>& v,
                              const vecType<T, N, B>& u) {
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

template <typename T, size_t N, typename>
constexpr tvec<bool, N> notEqual(T x, const tvec<T, N>& v) {
  return tvec<bool, N>(notEqual(x, v.recursive.head),
                       notEqual(x, v.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> notEqual(U x, const vecType<T, N, A>& v) {
  return notEqual(static_cast<T>(x), vec_cast(v));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> notEqual(const tvec<T, N>& v, T x) {
  return tvec<bool, N>(notEqual(v.recursive.head, x),
                       notEqual(v.recursive.tail, x));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<bool, N> notEqual(const vecType<T, N, A>& v, U x) {
  return notEqual(vec_cast(v), static_cast<T>(x));
}
template <typename T, size_t N, typename>
constexpr tvec<bool, N> notEqual(const tvec<T, N>& v, const tvec<T, N>& u) {
  return tvec<bool, N>(notEqual(v.recursive.head, u.recursive.head),
                       notEqual(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<bool, N> notEqual(const vecType<T, N, A>& v,
                                 const vecType<T, N, B>& u) {
  return notEqual(vec_cast(v), vec_cast(u));
}


constexpr bool any(bool x) { return x; }

template <size_t N>
constexpr bool any(const tvec<bool, N>& v) {
  return v.recursive.head or any(v.recursive.tail);
}
template <size_t N, typename A>
constexpr bool any(const vecType<bool, N, A>& v) {
  return any(vec_cast(v));
}


constexpr bool all(bool x) { return x; }

template <size_t N>
constexpr bool all(const tvec<bool, N>& v) {
  return v.recursive.head and all(v.recursive.tail);
}
template <size_t N, typename A>
constexpr bool all(const vecType<bool, N, A>& v) {
  return all(vec_cast(v));
}


template <size_t N>
constexpr tvec<bool, N> operator!(const tvec<bool, N> & v) {
  return tvec<bool, N>(not v.recursive.head, not v.recursive.tail);
}
template <size_t N, typename A>
constexpr tvec<bool, N> operator!(const vecType<bool, N, A> & v) {
  return not vec_cast(v);
}

#endif