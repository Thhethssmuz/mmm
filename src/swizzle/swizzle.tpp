#pragma once

template <typename T, size_t N, size_t... Elems>
constexpr swizzle<T, N, Elems...>::operator tvec<T, sizeof...(Elems)>() const {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  return tvec<T,sizeof...(Elems)>(data[Elems]...);
}


template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::operator+=(T s) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] += s;
  return *this;
}
template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::
operator+=(const tvec<T, sizeof...(Elems)>& u) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] += u[i];
  return *this;
}


template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::operator-=(T s) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] -= s;
  return *this;
}
template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::
operator-=(const tvec<T, sizeof...(Elems)>& u) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] -= u[i];
  return *this;
}


template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::operator*=(T s) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] *= s;
  return *this;
}
template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::
operator*=(const tvec<T, sizeof...(Elems)>& u) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] *= u[i];
  return *this;
}


template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::operator/=(T s) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] /= s;
  return *this;
}
template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::
operator/=(const tvec<T, sizeof...(Elems)>& u) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] /= u[i];
  return *this;
}


template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::operator=(T s) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] = s;
  return *this;
}
template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::
operator=(const swizzle<T, N, Elems...>& u) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] = u.data[es[i]];
  return *this;
}
template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::
operator=(const tvec<T, sizeof...(Elems)>& u) {
  static_assert(typefu::max<Elems...>::value < N,
                "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]] = u[i];
  return *this;
}


template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::operator++() {
  static_assert(typefu::max<Elems...>::value < N,
              "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]]++;
  return *this;
}
template <typename T, size_t N, size_t... Elems>
tvec<T, sizeof...(Elems)> swizzle<T, N, Elems...>::operator++(int) {
  static_assert(typefu::max<Elems...>::value < N,
              "vector swizzle out of bounds");

  tvec<T, sizeof...(Elems)> tmp = *this;
  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]]++;
  return tmp;
}


template <typename T, size_t N, size_t... Elems>
swizzle<T, N, Elems...>& swizzle<T, N, Elems...>::operator--() {
  static_assert(typefu::max<Elems...>::value < N,
              "vector swizzle out of bounds");

  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]]--;
  return *this;
}
template <typename T, size_t N, size_t... Elems>
tvec<T, sizeof...(Elems)> swizzle<T, N, Elems...>::operator--(int) {
  static_assert(typefu::max<Elems...>::value < N,
              "vector swizzle out of bounds");

  tvec<T, sizeof...(Elems)> tmp = *this;
  size_t es[sizeof...(Elems)] = {Elems...};
  for (size_t i = 0; i < sizeof...(Elems); ++i)
    data[es[i]]--;
  return tmp;
}
