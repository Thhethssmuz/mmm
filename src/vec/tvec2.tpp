#pragma once

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
template <typename U, typename>
constexpr tvec<T, 2>::tvec(const tvec<U, 2>& v)
  : recursive{T(v.recursive.head), T(v.recursive.tail)} {}

template <typename T>
template <typename U, typename A, typename>
constexpr tvec<T, 2>::tvec(const vecType<U, 2, A>& v)
  : tvec<T, 2>(vec_cast(v)) {}


template <typename T>
template <typename... Ts>
constexpr tvec<T, 2>::tvec(T x, T y, Ts...)
  : recursive{x, y} {}

template <typename T>
template <size_t L, typename... Ts>
constexpr tvec<T, 2>::tvec(T x, const tvec<T, L>& xs, Ts...)
  : recursive{x, xs[0]} {}

template <typename T>
template <size_t L, size_t Elem, size_t... Elems, typename... Ts>
constexpr tvec<T, 2>::tvec(T x, const swizzle<T, L, Elem, Elems...>& xs, Ts...)
  : recursive{x, xs.data[Elem]} {
  static_assert(typefu::max<Elem, Elems...>::value < L,
                "vector swizzle out of bounds");
}
template <typename T>
template <size_t L, size_t K, typename... Ts>
constexpr tvec<T, 2>::tvec(T x, const tmat<T, L, K>& xs, Ts...)
  : recursive{x, xs.recursive.head.recursive.head} {}


template <typename T>
template <size_t L, typename... Ts>
constexpr tvec<T, 2>::tvec(const tvec<T, L>& xs, Ts...)
  : recursive{xs[0], xs[1]} {}

template <typename T>
template <size_t L, size_t... Elems, typename... Ts>
constexpr tvec<T, 2>::tvec(const swizzle<T, L, Elems...>& xs, Ts... ys)
  : tvec<T, 2>(xs.data[Elems]..., ys...) {
  static_assert(typefu::max<Elems...>::value < L,
                "vector swizzle out of bounds");
}
template <typename T>
template <size_t L, size_t K, typename... Ts>
constexpr tvec<T, 2>::tvec(const tmat<T, L, K>& xs, Ts...)
  : tvec<T, 2>(xs.recursive.head) {}


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
