#ifndef mmm_vec_func_geo_tpp
#define mmm_vec_func_geo_tpp

template <typename T, typename>
constexpr typefu::promotef<T> length(T x) {
  typedef typefu::promotef<T> type;
  return abs(type(x));
}

template <typename T, size_t N, typename>
constexpr typefu::promotef<T> length(const tvec<T, N>& v) {
  typedef typefu::promotef<T> type;
  return sqrt(type(dot(v, v)));
}
template <typename T, size_t N, typename A, typename>
constexpr typefu::promotef<T> length(const vecType<T, N, A>& v) {
  return length(vec_cast(v));
}


template <typename T, typename>
constexpr T distance(T p0, T p1) {
  return abs(p0 - p1);
}
template <typename T, typename U, typename>
constexpr typefu::promote<T, U> distance(T p0, U p1) {
  typedef typefu::promote<T, U> type;
  return distance(type(p0), type(p1));
}

template <typename T, size_t N, typename>
constexpr typefu::promotef<T> distance(const tvec<T, N>& p0,
                                       const tvec<T, N>& p1) {
  return length(p0 - p1);
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr typefu::promotef<T> distance(const vecType<T, N, A>& p0,
                                       const vecType<T, N, B>& p1) {
  return distance(vec_cast(p0), vec_cast(p1));
}


template <typename T, typename>
constexpr T dot(T x, T y) {
  return x * y;
}
template <typename T, typename U, typename>
constexpr typefu::promote<T, U> dot(T x, U y) {
  typedef typefu::promote<T, U> type;
  return dot(type(x), type(y));
}

template <typename T, size_t N, typename>
constexpr T dot(const tvec<T, N>& v, const tvec<T, N>& u) {
  return sum(v * u);
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr T dot(const vecType<T, N, A>& v, const vecType<T, N, B>& u) {
  return dot(vec_cast(v), vec_cast(u));
}


template <typename T, typename>
constexpr tvec<T, 3> cross(const tvec<T, 3>& v, const tvec<T, 3>& u) {
  return tvec<T, 3>(v[1] * u[2] - v[2] * u[1], v[2] * u[0] - v[0] * u[2],
                    v[0] * u[1] - v[1] * u[0]);
}
template <typename T, typename A, typename B, typename>
constexpr tvec<T, 3> cross(const vecType<T, 3, A>& v,
                           const vecType<T, 3, B>& u) {
  return cross(vec_cast(v), vec_cast(u));
}


template <typename T, typename>
constexpr T normalize(T) {
  return T(1);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> normalize(const tvec<T, N>& v) {
  return v / length(v);
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> normalize(const vecType<T, N, A>& v) {
  return normalize(vec_cast(v));
}

#endif