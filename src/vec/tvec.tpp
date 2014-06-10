#ifndef mmm_vec_tvec_tpp
#define mmm_vec_tvec_tpp

template <typename T, size_t n>
constexpr tvec<T, n>::tvec()
  : data{0} {}

template <typename T, size_t n>
constexpr tvec<T, n>::tvec(T x)
  : recursive{x, tvec<T, n - 1>(x)} {}

template <typename T, size_t n>
constexpr tvec<T, n>::tvec(T x, tvec<T, n - 1>&& xs)
  : recursive{x, std::move(xs)} {}

template <typename T, size_t n>
constexpr tvec<T, n>::tvec(T x, const tvec<T, n - 1>& xs)
  : recursive{x, xs} {}


template <typename T, size_t n>
constexpr tvec<T, n>::tvec(tvec<T, n>&& v)
  : recursive{std::move(v.recursive.head), std::move(v.recursive.tail)} {}

template <typename T, size_t n>
constexpr tvec<T, n>::tvec(const tvec<T, n>& v)
  : recursive{v.recursive.head, v.recursive.tail} {}


template <typename T, size_t n>
template <typename... Ts, typename>
constexpr tvec<T, n>::tvec(T x, Ts... xs)
  : recursive{x, tvec<T, n - 1>(xs...)} {}

template <typename T, size_t n>
template <size_t l, typename... Ts, typename>
constexpr tvec<T, n>::tvec(const tvec<T, l>& xs, Ts... ys)
  : tvec<T, n>(xs.recursive.head, xs.recursive.tail, ys...) {}

template <typename T, size_t n>
template <size_t l, size_t... elems, typename... Ts, typename>
constexpr tvec<T, n>::tvec(const swizzle<T, l, elems...>& xs, Ts... ys)
  : tvec<T, n>(xs.data[elems]..., ys...) {}


template <typename T, size_t n>
constexpr T tvec<T, n>::operator[](size_t i) const {
  return data[i];
}
template <typename T, size_t n>
T& tvec<T, n>::operator[](size_t i) {
  return data[i];
}


template <typename T, size_t n>
tvec<T, n>::operator T*() {
  return data;
}

template <typename T, size_t n>
tvec<T, n>& tvec<T, n>::operator=(const tvec<T, n>& v) {
  recursive.head = v.recursive.head;
  recursive.tail = v.recursive.tail;
  return *this;
}


template <typename T, size_t n>
template <size_t... es>
swizzle<T, n, es...>& tvec<T, n>::swizzleElems() {
  return *(reinterpret_cast<swizzle<T, n, es...>*>(this));
}

#endif