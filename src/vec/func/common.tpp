#ifndef mmm_vec_func_common_tpp
#define mmm_vec_func_common_tpp

template <typename T, size_t N, typename>
constexpr tvec<T, N> abs(const tvec<T, N>& x) {
  return tvec<T, N>(abs(x.recursive.head), abs(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> abs(const vecType<T, N, A>& x) {
  return abs(vec_cast(x));
}


template <typename T, typename>
constexpr T sign(T x) {
  return x > T(0) ? T(1) : x < T(0) ? T(-1) : T(0);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> sign(const tvec<T, N>& x) {
  return tvec<T, N>(sign(x.recursive.head), sign(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> sign(const vecType<T, N, A>& x) {
  return sign(vec_cast(x));
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> floor(const tvec<T, N>& x) {
  return tvec<T, N>(floor(x.recursive.head), floor(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> floor(const vecType<T, N, A>& x) {
  return floor(vec_cast(x));
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> ceil(const tvec<T, N>& x) {
  return tvec<T, N>(ceil(x.recursive.head), ceil(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> ceil(const vecType<T, N, A>& x) {
  return ceil(vec_cast(x));
}


template <typename T, typename>
constexpr typefu::promotef<T> fract(T x) {
  return x - floor(x);
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> fract(const tvec<T, N>& x) {
  return tvec<T, N>(fract(x.recursive.head), fract(x.recursive.tail));
}
template <typename T, size_t N, typename A, typename>
constexpr tvec<T, N> fract(const vecType<T, N, A>& x) {
  return fract(vec_cast(x));
}


template <typename T, typename, typename>
constexpr T mod(T x, T y) {
  return (x < 0) ^ (y < 0) ? y + x - y * (x / y) : x - y * (x / y);
}
template <typename T, typename>
constexpr T mod(T x, T y) {
  return x - y * floor(x / y);
}
template <typename T, typename U, typename>
constexpr typefu::promote<T, U> mod(T x, U y) {
  typedef typefu::promote<T, U> type;
  return mod(type(x), type(y));
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> mod(T x, const tvec<T, N>& y) {
  return tvec<T, N>(mod(x, y.recursive.head), mod(x, y.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> mod(U x, const vecType<T, N, A>& y) {
  return mod(static_cast<T>(x), vec_cast(y));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> mod(const tvec<T, N>& x, T y) {
  return tvec<T, N>(mod(x.recursive.head, y), mod(x.recursive.tail, y));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> mod(const vecType<T, N, A>& x, U y) {
  return mod(vec_cast(x), static_cast<T>(y));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> mod(const tvec<T, N>& x, const tvec<T, N>& y) {
  return tvec<T, N>(mod(x.recursive.head, y.recursive.head),
                    mod(x.recursive.tail, y.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> mod(const vecType<T, N, A>& x, const vecType<T, N, B>& y) {
  return mod(vec_cast(x), vec_cast(y));
}


template <typename T, typename>
constexpr T min(T x, T y) {
  return x <= y ? x : y;
}
template <typename T, typename U, typename>
constexpr typefu::promote<T, U> min(T x, U y) {
  typedef typefu::promote<T, U> type;
  return min(type(x), type(y));
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> min(T x, const tvec<T, N>& y) {
  return tvec<T, N>(min(x, y.recursive.head), min(x, y.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> min(U x, const vecType<T, N, A>& y) {
  return min(static_cast<T>(x), vec_cast(y));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> min(const tvec<T, N>& x, T y) {
  return tvec<T, N>(min(x.recursive.head, y), min(x.recursive.tail, y));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> min(const vecType<T, N, A>& x, U y) {
  return min(vec_cast(x), static_cast<T>(y));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> min(const tvec<T, N>& x, const tvec<T, N>& y) {
  return tvec<T, N>(min(x.recursive.head, y.recursive.head),
                    min(x.recursive.tail, y.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> min(const vecType<T, N, A>& x, const vecType<T, N, B>& y) {
  return min(vec_cast(x), vec_cast(y));
}


template <typename T, typename>
constexpr T max(T x, T y) {
  return x >= y ? x : y;
}
template <typename T, typename U, typename>
constexpr typefu::promote<T, U> max(T x, U y) {
  typedef typefu::promote<T, U> type;
  return max(type(x), type(y));
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> max(T x, const tvec<T, N>& y) {
  return tvec<T, N>(max(x, y.recursive.head), max(x, y.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> max(U x, const vecType<T, N, A>& y) {
  return max(static_cast<T>(x), vec_cast(y));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> max(const tvec<T, N>& x, T y) {
  return tvec<T, N>(max(x.recursive.head, y), max(x.recursive.tail, y));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> max(const vecType<T, N, A>& x, U y) {
  return max(vec_cast(x), static_cast<T>(y));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> max(const tvec<T, N>& x, const tvec<T, N>& y) {
  return tvec<T, N>(max(x.recursive.head, y.recursive.head),
                    max(x.recursive.tail, y.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> max(const vecType<T, N, A>& x, const vecType<T, N, B>& y) {
  return max(vec_cast(x), vec_cast(y));
}


template <typename T, typename>
constexpr T clamp(T x, T minVal, T maxVal) {
  return x < minVal ? minVal : x > maxVal ? maxVal : x;
}
template <typename T, typename U, typename V, typename>
constexpr typefu::promote<T, U, V> clamp(T x, U minVal, V maxVal) {
  typedef typefu::promote<T, U, V> type;
  return clamp(type(x), type(minVal), type(maxVal));
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> clamp(const tvec<T, N>& x, T minVal, T maxVal) {
  return tvec<T, N>(clamp(x.recursive.head, minVal, maxVal),
                    clamp(x.recursive.tail, minVal, maxVal));
}
template <typename T, typename U, typename V, size_t N, typename A, typename>
constexpr tvec<T, N> clamp(const vecType<T, N, A>& x, U minVal, V maxVal) {
  return clamp(vec_cast(x), static_cast<T>(minVal), static_cast<T>(maxVal));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> clamp(const tvec<T, N>& x, const tvec<T, N>& minVal,
                           const tvec<T, N>& maxVal) {
  return tvec<T, N>(
    clamp(x.recursive.head, minVal.recursive.head, maxVal.recursive.head),
    clamp(x.recursive.tail, minVal.recursive.tail, maxVal.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename C, typename>
constexpr tvec<T, N> clamp(const vecType<T, N, A>& x,
                           const vecType<T, N, B>& minVal,
                           const vecType<T, N, C>& maxVal) {
  return clamp(vec_cast(x), vec_cast(minVal), vec_cast(maxVal));
}


template <typename T, typename>
constexpr T mix(T x, T y, T a) {
  return x * (T(1) - a) + y * a;
}
template <typename T, typename U, typename V, typename>
constexpr typefu::promotef<T, U, V> mix(T x, U y, V a) {
  typedef typefu::promotef<T, U, V> type;
  return mix(type(x), type(y), type(a));
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> mix(const tvec<T, N>& x, const tvec<T, N>& y, T a) {
  return tvec<T, N>(mix(x.recursive.head, y.recursive.head, a),
                    mix(x.recursive.tail, y.recursive.tail, a));
}
template <typename T, typename U, size_t N, typename A, typename B, typename,
          typename>
constexpr tvec<T, N> mix(const vecType<T, N, A>& x, const vecType<T, N, B>& y,
                         U a) {
  return mix(vec_cast(x), vec_cast(y), static_cast<T>(a));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> mix(const tvec<T, N>& x, const tvec<T, N>& y,
                         const tvec<T, N>& a) {
  return tvec<T, N>(mix(x.recursive.head, y.recursive.head, a.recursive.head),
                    mix(x.recursive.tail, y.recursive.tail, a.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename C, typename>
constexpr tvec<T, N> mix(const vecType<T, N, A>& x, const vecType<T, N, B>& y,
                         const vecType<T, N, C>& a) {
  return mix(vec_cast(x), vec_cast(y), vec_cast(a));
}


template <typename T, typename>
constexpr T step(T edge, T x) {
  return x < edge ? T(0) : T(1);
}
template <typename T, typename U, typename>
constexpr typefu::promote<T, U> step(T edge, U x) {
  typedef typefu::promote<T, U> type;
  return step(type(edge), type(x));
}

template <typename T, size_t N, typename>
constexpr tvec<T, N> step(T edge, const tvec<T, N>& x) {
  return tvec<T, N>(step(edge, x.recursive.head), step(edge, x.recursive.tail));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> step(U edge, const vecType<T, N, A>& x) {
  return step(static_cast<T>(edge), vec_cast(x));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> step(const tvec<T, N>& edge, T x) {
  return tvec<T, N>(step(edge.recursive.head, x), step(edge.recursive.tail, x));
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> step(const vecType<T, N, A>& edge, U x) {
  return step(vec_cast(edge), static_cast<T>(x));
}
template <typename T, size_t N, typename>
constexpr tvec<T, N> step(const tvec<T, N>& edge, const tvec<T, N>& x) {
  return tvec<T, N>(step(edge.recursive.head, x.recursive.head),
                    step(edge.recursive.tail, x.recursive.tail));
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr tvec<T, N> step(const vecType<T, N, A>& edge,
                          const vecType<T, N, B>& x) {
  return step(vec_cast(edge), vec_cast(x));
}

#endif