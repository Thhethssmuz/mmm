#pragma once

template <typename T>
constexpr tvec<T, 3>::tvec()
  : recursive{0, tvec<T, 2>(0)} {}

template <typename T>
constexpr tvec<T, 3>::tvec(T x)
  : recursive{x, tvec<T, 2>(x)} {}

template <typename T>
constexpr tvec<T, 3>::tvec(T x, tvec<T, 2>&& xs)
  : recursive{x, std::move(xs)} {}

template <typename T>
constexpr tvec<T, 3>::tvec(T x, const tvec<T, 2>& xs)
  : recursive{x, xs} {}


template <typename T>
constexpr tvec<T, 3>::tvec(tvec<T, 3>&& v)
  : recursive{std::move(v.recursive.head), std::move(v.recursive.tail)} {}

template <typename T>
constexpr tvec<T, 3>::tvec(const tvec<T, 3>& v)
  : recursive{v.recursive.head, v.recursive.tail} {}


template <typename T>
template <typename U, typename>
constexpr tvec<T, 3>::tvec(const tvec<U, 3>& v)
  : recursive{T(v.recursive.head), tvec<T, 2>(v.recursive.tail)} {}

template <typename T>
template <typename U, typename A, typename>
constexpr tvec<T, 3>::tvec(const vecType<U, 3, A>& v)
  : tvec<T, 3>(vec_cast(v)) {}


template <typename T>
template <typename... Ts, typename>
constexpr tvec<T, 3>::tvec(T x, Ts... xs)
  : recursive{x, tvec<T, 2>(xs...)} {}

template <typename T>
template <size_t L, typename... Ts, typename>
constexpr tvec<T, 3>::tvec(const tvec<T, L>& xs, Ts... ys)
  : tvec<T, 3>(xs.recursive.head, xs.recursive.tail, ys...) {}

template <typename T>
template <size_t L, size_t... Elems, typename... Ts, typename>
constexpr tvec<T, 3>::tvec(const swizzle<T, L, Elems...>& xs, Ts... ys)
  : tvec<T, 3>(xs.data[Elems]..., ys...) {
  static_assert(typefu::max<Elems...>::value < L,
                "vector swizzle out of bounds");
}
template <typename T>
template <size_t L, size_t K, typename... Ts, typename>
constexpr tvec<T, 3>::tvec(const tmat<T, L, K>& xs, Ts... ys)
  : tvec<T, 3>(xs.recursive.head, xs.recursive.tail, ys...) {}


template <typename T>
constexpr T tvec<T, 3>::operator[](size_t i) const {
  return data[i];
}
template <typename T>
T& tvec<T, 3>::operator[](size_t i) {
  return data[i];
}


template <typename T>
tvec<T, 3>::operator T*() {
  return data;
}

template <typename T>
tvec<T, 3>& tvec<T, 3>::operator=(const tvec<T, 3>& v) {
  recursive.head = v.recursive.head;
  recursive.tail = v.recursive.tail;
  return *this;
}


template <typename T>
template <size_t... Elems>
swizzle<T, 3, Elems...>& tvec<T, 3>::swizzleElems() {
  return *(reinterpret_cast<swizzle<T, 3, Elems...>*>(this));
}

template <typename T>
template <size_t Start, size_t End>
typefu::swizzle_range<T, 3, Start, End>& tvec<T, 3>::swizzleRange() {
  typedef typefu::swizzle_range<T, 3, Start, End> type;
  return *(reinterpret_cast<type*>(this));
}
