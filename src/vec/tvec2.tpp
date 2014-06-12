#ifndef mmm_vec_tvec2_tpp
#define mmm_vec_tvec2_tpp

template <typename T>
constexpr tvec<T, 2>::tvec()
  : data{0} {}

template <typename T>
constexpr tvec<T, 2>::tvec(T x, T y)
  : data{x, y} {}

template <typename T>
constexpr tvec<T, 2>::tvec(T x)
  : data{x, x} {}


template <typename T>
constexpr tvec<T, 2>::tvec(tvec<T, 2>&& v)
  : recursive{std::move(v.recursive.head), std::move(v.recursive.tail)} {}

template <typename T>
constexpr tvec<T, 2>::tvec(const tvec<T, 2>& v)
  : recursive{v.recursive.head, v.recursive.tail} {}


template <typename T>
template <typename... Ts>
constexpr tvec<T, 2>::tvec(T x, T y, Ts...)
  : recursive{x, y} {}

template <typename T>
template <size_t l, typename... Ts>
constexpr tvec<T, 2>::tvec(T x, const tvec<T, l>& xs, Ts...)
  : recursive{x, xs[0]} {}

template <typename T>
template <size_t l, size_t elem, size_t... elems, typename... Ts>
constexpr tvec<T, 2>::tvec(T x, const swizzle<T, l, elem, elems...>& xs, Ts...)
  : recursive{x, xs.data[elem]} {
  static_assert(typefu::max<elem, elems...>::value < l,
                "vector swizzle out of bounds");
}

template <typename T>
template <size_t l, typename... Ts>
constexpr tvec<T, 2>::tvec(const tvec<T, l>& xs, Ts...)
  : recursive{xs[0], xs[1]} {}

template <typename T>
template <size_t l, size_t... elems, typename... Ts>
constexpr tvec<T, 2>::tvec(const swizzle<T, l, elems...>& xs, Ts... ys)
  : tvec<T, 2>(xs.data[elems]..., ys...) {
  static_assert(typefu::max<elems...>::value < l,
                "vector swizzle out of bounds");
}


template <typename T>
constexpr T tvec<T, 2>::operator[](size_t i) const {
  return data[i];
}

template <typename T>
T& tvec<T, 2>::operator[](size_t i) {
  return data[i];
}


template <typename T>
tvec<T, 2>::operator T*() {
  return data;
}


template <typename T>
tvec<T, 2>& tvec<T, 2>::operator=(const tvec<T, 2>& v) {
  recursive.head = v.recursive.head;
  recursive.tail = v.recursive.tail;
  return *this;
}

#endif