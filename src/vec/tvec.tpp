#pragma once

template <typename T, size_t N>
constexpr tvec<T, N>::tvec()
  : data{0} {}

template <typename T, size_t N>
constexpr tvec<T, N>::tvec(T x)
  : recursive{x, tvec<T, N - 1>(x)} {}

template <typename T, size_t N>
constexpr tvec<T, N>::tvec(T x, tvec<T, N - 1>&& xs)
  : recursive{x, std::move(xs)} {}

template <typename T, size_t N>
constexpr tvec<T, N>::tvec(T x, const tvec<T, N - 1>& xs)
  : recursive{x, xs} {}


template <typename T, size_t N>
constexpr tvec<T, N>::tvec(tvec<T, N>&& v)
  : recursive{std::move(v.recursive.head), std::move(v.recursive.tail)} {}

template <typename T, size_t N>
constexpr tvec<T, N>::tvec(const tvec<T, N>& v)
  : recursive{v.recursive.head, v.recursive.tail} {}


template <typename T, size_t N>
template <typename U, typename>
constexpr tvec<T, N>::tvec(const tvec<U, N>& v)
  : recursive{T(v.recursive.head), tvec<T, N - 1>(v.recursive.tail)} {}

template <typename T, size_t N>
template <typename U, typename A, typename>
constexpr tvec<T, N>::tvec(const vecType<U, N, A>& v)
  : tvec<T, N>(vec_cast(v)) {}


template <typename T, size_t N>
template <typename... Ts, typename>
constexpr tvec<T, N>::tvec(T x, Ts... xs)
  : recursive{x, tvec<T, N - 1>(xs...)} {}

template <typename T, size_t N>
template <size_t L, typename... Ts, typename>
constexpr tvec<T, N>::tvec(const tvec<T, L>& xs, Ts... ys)
  : tvec<T, N>(xs.recursive.head, xs.recursive.tail, ys...) {}

template <typename T, size_t N>
template <size_t L, size_t... Elems, typename... Ts, typename>
constexpr tvec<T, N>::tvec(const swizzle<T, L, Elems...>& xs, Ts... ys)
  : tvec<T, N>(xs.data[Elems]..., ys...) {
  static_assert(typefu::max<Elems...>::value < L,
                "vector swizzle out of bounds");
}
template <typename T, size_t N>
template <size_t L, size_t K, typename... Ts, typename>
constexpr tvec<T, N>::tvec(const tmat<T, L, K>& xs, Ts... ys)
  : tvec<T, N>(xs.recursive.head, xs.recursive.tail, ys...) {}


template <typename T, size_t N>
constexpr T tvec<T, N>::operator[](size_t i) const {
  return data[i];
}
template <typename T, size_t N>
T& tvec<T, N>::operator[](size_t i) {
  return data[i];
}


template <typename T, size_t N>
tvec<T, N>::operator T*() {
  return data;
}

template <typename T, size_t N>
tvec<T, N>& tvec<T, N>::operator=(const tvec<T, N>& v) {
  recursive.head = v.recursive.head;
  recursive.tail = v.recursive.tail;
  return *this;
}


template <typename T, size_t N>
template <size_t... Elems>
swizzle<T, N, Elems...>& tvec<T, N>::swizzleElems() {
  return *(reinterpret_cast<swizzle<T, N, Elems...>*>(this));
}

template <typename T, size_t N>
template <size_t Start, size_t End>
typefu::swizzle_range<T, N, Start, End>& tvec<T, N>::swizzleRange() {
  typedef typefu::swizzle_range<T, N, Start, End> type;
  return *(reinterpret_cast<type*>(this));
}
