#ifndef mmm_vec_func_trig_tpp
#define mmm_vec_func_trig_tpp

constexpr float radians(float degrees) { return degrees * PI / 180.0f; }
constexpr double radians(double degrees) { return degrees * dPI / 180.0; }
constexpr long double radians(long double degrees) {
  return degrees * lPI / 180.0l;
}
template <typename T, typename>
constexpr typefu::promotef<T> radians(T degrees) {
  typedef typefu::promotef<T> type;
  return radians(type(degrees));
}

template <typename T, size_t n, typename>
constexpr tvec<T, n> radians(const tvec<T, n>& degrees) {
  return tvec<T, n>(radians(degrees.recursive.head),
                    radians(degrees.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> radians(const vecType<T, n, A>& degrees) {
  return radians(vec_cast(degrees));
}


constexpr float degrees(float radians) { return radians * 180.0f / PI; }
constexpr double degrees(double radians) { return radians * 180.0 / dPI; }
constexpr long double degrees(long double radians) {
  return radians * 180.0l / lPI;
}
template <typename T, typename>
constexpr typefu::promotef<T> degrees(T radians) {
  typedef typefu::promotef<T> type;
  return degrees(type(radians));
}

template <typename T, size_t n, typename>
constexpr tvec<T, n> degrees(const tvec<T, n>& radians) {
  return tvec<T, n>(degrees(radians.recursive.head),
                    degrees(radians.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> degrees(const vecType<T, n, A>& radians) {
  return degrees(vec_cast(radians));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> sin(const tvec<T, n>& angle) {
  return tvec<T, n>(sin(angle.recursive.head), sin(angle.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> sin(const vecType<T, n, A>& angle) {
  return sin(vec_cast(angle));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> cos(const tvec<T, n>& angle) {
  return tvec<T, n>(cos(angle.recursive.head), cos(angle.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> cos(const vecType<T, n, A>& angle) {
  return cos(vec_cast(angle));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> tan(const tvec<T, n>& angle) {
  return tvec<T, n>(tan(angle.recursive.head), tan(angle.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> tan(const vecType<T, n, A>& angle) {
  return tan(vec_cast(angle));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> asin(const tvec<T, n>& x) {
  return tvec<T, n>(asin(x.recursive.head), asin(x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> asin(const vecType<T, n, A>& x) {
  return asin(vec_cast(x));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> acos(const tvec<T, n>& x) {
  return tvec<T, n>(acos(x.recursive.head), acos(x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> acos(const vecType<T, n, A>& x) {
  return acos(vec_cast(x));
}


template <typename T, size_t n, typename>
constexpr tvec<T, n> atan(const tvec<T, n>& y_over_x) {
  return tvec<T, n>(atan(y_over_x.recursive.head),
                    atan(y_over_x.recursive.tail));
}
template <typename T, size_t n, typename A, typename>
constexpr tvec<T, n> atan(const vecType<T, n, A>& y_over_x) {
  return atan(vec_cast(y_over_x));
}


template <typename T, typename>
constexpr T atan(T y, T x) {
  return atan2(y, x);
}
template <typename T, typename U, typename>
constexpr typefu::promotef<T, U> atan(T y, U x) {
  typedef typefu::promotef<T, U> type;
  return atan(type(y), type(x));
}

template <typename T, size_t n, typename>
constexpr tvec<T, n> atan(T y, const tvec<T, n>& x) {
  return tvec<T, n>(atan(y, x.recursive.head), atan(y, x.recursive.tail));
}
template <typename T, typename U, size_t n, typename A, typename, typename>
constexpr tvec<T, n> atan(U y, const vecType<T, n, A>& x) {
  return atan(static_cast<T>(y), vec_cast(x));
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> atan(const tvec<T, n>& y, T x) {
  return tvec<T, n>(atan(y.recursive.head, x), atan(y.recursive.tail, x));
}
template <typename T, typename U, size_t n, typename A, typename, typename>
constexpr tvec<T, n> atan(const vecType<T, n, A>& y, U x) {
  return atan(vec_cast(y), static_cast<T>(x));
}
template <typename T, size_t n, typename>
constexpr tvec<T, n> atan(const tvec<T, n>& y, const tvec<T, n>& x) {
  return tvec<T, n>(atan(y.recursive.head, x.recursive.head),
                    atan(y.recursive.tail, x.recursive.tail));
}
template <typename T, size_t n, typename A, typename B, typename>
constexpr tvec<T, n> atan(const vecType<T, n, A>& y,
                          const vecType<T, n, B>& x) {
  return atan(vec_cast(y), vec_cast(x));
}

#endif