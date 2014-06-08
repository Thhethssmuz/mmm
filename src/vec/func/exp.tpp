#ifndef mmm_vec_func_exp_tpp
#define mmm_vec_func_exp_tpp

template <typename T, size_t n, typename>
constexpr tvec<T, n> pow(T s, const tvec<T, n>& v) {
  return tvec<T, n>(pow(s, v.recursive.head), pow(s, v.recursive.tail));
}
template <typename T, typename U, size_t n, typename A, typename, typename>
constexpr tvec<T, n> pow(U s, const vecType<T, n, A>& v) {
  return pow(static_cast<T>(s), vec_cast(v));
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> pow(const tvec<T, n>& v, T s) {
  return tvec<T, n>(pow(v.recursive.head, s), pow(v.recursive.tail, s));
}
template <typename T, typename U, size_t n, typename A, typename, typename>
constexpr tvec<T, n> pow(const vecType<T, n, A>& v, U s) {
  return pow(vec_cast(v), static_cast<T>(s));
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> pow(const tvec<T, n>& v, const tvec<T, n>& u) {
  return tvec<T, n>(pow(v.recursive.head, u.recursive.head),
                    pow(v.recursive.tail, u.recursive.tail));
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<T, n> pow(const vecType<T, n, A>& v, const vecType<T, n, B>& u) {
  return pow(vec_cast(v), vec_cast(u));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> exp(const tvec<T, n>& x) {
  return tvec<T, n>(exp(x.recursive.head), exp(x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> exp(const vecType<T, n, A>& x) {
  return exp(vec_cast(x));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> log(const tvec<T, n>& x) {
  return tvec<T, n>(log(x.recursive.head), log(x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> log(const vecType<T, n, A>& x) {
  return log(vec_cast(x));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> exp2(const tvec<T, n>& x) {
  return tvec<T, n>(exp2(x.recursive.head), exp2(x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> exp2(const vecType<T, n, A>& x) {
  return exp2(vec_cast(x));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> log2(const tvec<T, n>& x) {
  return tvec<T, n>(log2(x.recursive.head), log2(x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> log2(const vecType<T, n, A>& x) {
  return log2(vec_cast(x));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> sqrt(const tvec<T, n>& x) {
  return tvec<T, n>(sqrt(x.recursive.head), sqrt(x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> sqrt(const vecType<T, n, A>& x) {
  return sqrt(vec_cast(x));
}


template <typename T, typename>
constexpr typefu::promotef<T> inversesqrt(T x) {
  typedef typefu::promotef<T> type;
  return type(1) / sqrt(x);
}

template <typename T, size_t n, typename>
constexpr tvec<T, n> inversesqrt(const tvec<T, n>& x) {
  return tvec<T, n>(inversesqrt(x.recursive.head),
                    inversesqrt(x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> inversesqrt(const vecType<T, n, A>& x) {
  return inversesqrt(vec_cast(x));
}

#endif