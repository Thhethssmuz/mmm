#pragma once

template <typename T, typename>
constexpr typefu::promotef<T> radians(T degrees) {
  typedef typefu::promotef<T> type;
  return type(degrees) * constants<type>::pi / type(180);
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> radians(const tvec<T, N>& degrees) {
  return tvec<T, N>(radians(degrees.recursive.head),
                    radians(degrees.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> radians(const vecType<T, N, A>& degrees) {
  return radians(vec_cast(degrees));
}


template <typename T, typename>
constexpr typefu::promotef<T> degrees(T radians) {
  typedef typefu::promotef<T> type;
  return type(radians) * type(180) / constants<type>::pi;
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> degrees(const tvec<T, N>& radians) {
  return tvec<T, N>(degrees(radians.recursive.head),
                    degrees(radians.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> degrees(const vecType<T, N, A>& radians) {
  return degrees(vec_cast(radians));
}


template <typename T, typename>
constexpr typefu::promotef<T> sin(T angle) {
  return std::sin(angle);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> sin(const tvec<T, N>& angle) {
  return tvec<T, N>(sin(angle.recursive.head), sin(angle.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> sin(const vecType<T, N, A>& angle) {
  return sin(vec_cast(angle));
}


template <typename T, typename>
constexpr typefu::promotef<T> cos(T angle) {
  return std::cos(angle);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> cos(const tvec<T, N>& angle) {
  return tvec<T, N>(cos(angle.recursive.head), cos(angle.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> cos(const vecType<T, N, A>& angle) {
  return cos(vec_cast(angle));
}


template <typename T, typename>
constexpr typefu::promotef<T> tan(T angle) {
  return std::tan(angle);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> tan(const tvec<T, N>& angle) {
  return tvec<T, N>(tan(angle.recursive.head), tan(angle.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> tan(const vecType<T, N, A>& angle) {
  return tan(vec_cast(angle));
}


template <typename T, typename>
constexpr typefu::promotef<T> asin(T x) {
  return std::asin(x);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> asin(const tvec<T, N>& x) {
  return tvec<T, N>(asin(x.recursive.head), asin(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> asin(const vecType<T, N, A>& x) {
  return asin(vec_cast(x));
}


template <typename T, typename>
constexpr typefu::promotef<T> acos(T x) {
  return std::acos(x);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> acos(const tvec<T, N>& x) {
  return tvec<T, N>(acos(x.recursive.head), acos(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> acos(const vecType<T, N, A>& x) {
  return acos(vec_cast(x));
}


template <typename T, typename>
constexpr typefu::promotef<T> atan(T y_over_x) {
  return std::atan(y_over_x);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> atan(const tvec<T, N>& y_over_x) {
  return tvec<T, N>(atan(y_over_x.recursive.head),
                    atan(y_over_x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> atan(const vecType<T, N, A>& y_over_x) {
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

template <typename T, size_t N, typename>
constexpr tvec<T, N> atan(T y, const tvec<T, N>& x) {
  return tvec<T, N>(atan(y, x.recursive.head), atan(y, x.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename, typename>
constexpr tvec<T, N> atan(U y, const vecType<T, N, A>& x) {
  return atan(static_cast<T>(y), vec_cast(x));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> atan(const tvec<T, N>& y, T x) {
  return tvec<T, N>(atan(y.recursive.head, x), atan(y.recursive.tail, x));
}
template <typename T, typename U, size_t N, typename A, typename, typename>
constexpr tvec<T, N> atan(const vecType<T, N, A>& y, U x) {
  return atan(vec_cast(y), static_cast<T>(x));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> atan(const tvec<T, N>& y, const tvec<T, N>& x) {
  return tvec<T, N>(atan(y.recursive.head, x.recursive.head),
                    atan(y.recursive.tail, x.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> atan(const vecType<T, N, A>& y,
                          const vecType<T, N, B>& x) {
  return atan(vec_cast(y), vec_cast(x));
}
