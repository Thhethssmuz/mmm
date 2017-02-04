#pragma once

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M>::tmat()
  : recursive{tvec<T, N>(0), tmat<T, N, M - 1>(0)} {}

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M>::tmat(T x)
  : recursive{tvec<T, N>(x), tmat<T, N, M - 1>(x)} {}

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M>::tmat(const tvec<T, N>& v, tmat<T, N, M - 1>&& vs)
  : recursive{v, std::move(vs)} {}

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M>::tmat(const tvec<T, N>& v, const tmat<T, N, M - 1>& vs)
  : recursive{v, vs} {}


template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M>::tmat(tmat<T, N, M>&& m)
  : recursive{std::move(m.recursive.head), std::move(m.recursive.tail)} {}

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M>::tmat(const tmat<T, N, M>& m)
  : recursive{m.recursive.head, m.recursive.tail} {}


template <typename T, size_t N, size_t M>
template <size_t L, typename>
constexpr tmat<T, N, M>::tmat(const tvec<T, L>& xs)
  : recursive{take<N>(xs), tmat<T, N, M - 1>(drop<N>(xs))} {}

template <typename T, size_t N, size_t M>
template <typename... Ts, typename>
constexpr tmat<T, N, M>::tmat(Ts... xs)
  : tmat<T, N, M>(tvec<T, typefu::components<Ts...>::value>(xs...)) {}


template <typename T, size_t N, size_t M>
constexpr tvec<T, N> tmat<T, N, M>::operator[](size_t i) const {
  return data[i];
}
template <typename T, size_t N, size_t M>
tvec<T, N>& tmat<T, N, M>::operator[](size_t i) {
  return data[i];
}
template <typename T, size_t N, size_t M>
tmat<T, N, M>::operator T*() {
  return rawdata;
}


template <typename T, size_t N, size_t M>
tmat<T, N, M>& tmat<T, N, M>::operator=(const tmat<T, N, M>& m) {
  recursive.head = m.recursive.head;
  recursive.tail = m.recursive.tail;
  return *this;
}
