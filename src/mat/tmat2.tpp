#pragma once

template <typename T, size_t M>
constexpr tmat<T, 2, M>::tmat()
  : recursive{tvec<T, M>(0), tvec<T, M>(0)} {}

template <typename T, size_t M>
constexpr tmat<T, 2, M>::tmat(T x)
  : recursive{tvec<T, M>(x), tvec<T, M>(x)} {}

template <typename T, size_t M>
constexpr tmat<T, 2, M>::tmat(const tvec<T, M>& v, const tvec<T, M>& u)
  : recursive{v, u} {}


template <typename T, size_t M>
constexpr tmat<T, 2, M>::tmat(tmat<T, 2, M>&& m)
  : recursive{std::move(m.recursive.head), std::move(m.recursive.tail)} {}

template <typename T, size_t M>
constexpr tmat<T, 2, M>::tmat(const tmat<T, 2, M>& m)
  : recursive{m.recursive.head, m.recursive.tail} {}


template <typename T, size_t M>
template <size_t L, typename>
constexpr tmat<T, 2, M>::tmat(const tvec<T, L>& xs)
  : recursive{take<M>(xs), take<M>(drop<M>(xs))} {}

template <typename T, size_t M>
template <typename... Ts, typename>
constexpr tmat<T, 2, M>::tmat(Ts... xs)
  : tmat<T, 2, M>(tvec<T, typefu::components<Ts...>::value>(xs...)) {}


template <typename T, size_t M>
constexpr tvec<T, M> tmat<T, 2, M>::operator[](size_t i) const {
  return data[i];
}
template <typename T, size_t M>
tvec<T, M>& tmat<T, 2, M>::operator[](size_t i) {
  return data[i];
}
template <typename T, size_t M>
tmat<T, 2, M>::operator T*() {
  return rawdata;
}


template <typename T, size_t M>
tmat<T, 2, M>& tmat<T, 2, M>::operator=(const tmat<T, 2, M>& m) {
  recursive.head = m.recursive.head;
  recursive.tail = m.recursive.tail;
  return *this;
}
