#pragma once

template <typename T, size_t N>
constexpr tmat<T, N, 2>::tmat()
  : recursive{tvec<T, N>(0), tvec<T, N>(0)} {}

template <typename T, size_t N>
constexpr tmat<T, N, 2>::tmat(T x)
  : recursive{tvec<T, N>(x), tvec<T, N>(x)} {}

template <typename T, size_t N>
constexpr tmat<T, N, 2>::tmat(const tvec<T, N>& v, const tvec<T, N>& u)
  : recursive{v, u} {}


template <typename T, size_t N>
constexpr tmat<T, N, 2>::tmat(tmat<T, N, 2>&& m)
  : recursive{std::move(m.recursive.head), std::move(m.recursive.tail)} {}

template <typename T, size_t N>
constexpr tmat<T, N, 2>::tmat(const tmat<T, N, 2>& m)
  : recursive{m.recursive.head, m.recursive.tail} {}


template <typename T, size_t N>
template <size_t L, typename>
constexpr tmat<T, N, 2>::tmat(const tvec<T, L>& xs)
  : recursive{take<N>(xs), take<N>(drop<N>(xs))} {}

template <typename T, size_t N>
template <typename... Ts, typename>
constexpr tmat<T, N, 2>::tmat(Ts... xs)
  : tmat<T, N, 2>(tvec<T, typefu::components<Ts...>::value>(xs...)) {}


template <typename T, size_t N>
constexpr tvec<T, N> tmat<T, N, 2>::operator[](size_t i) const {
  return data[i];
}
template <typename T, size_t N>
tvec<T, N>& tmat<T, N, 2>::operator[](size_t i) {
  return data[i];
}
template <typename T, size_t N>
tmat<T, N, 2>::operator T*() {
  return rawdata;
}


template <typename T, size_t N>
tmat<T, N, 2>& tmat<T, N, 2>::operator=(const tmat<T, N, 2>& m) {
  recursive.head = m.recursive.head;
  recursive.tail = m.recursive.tail;
  return *this;
}
