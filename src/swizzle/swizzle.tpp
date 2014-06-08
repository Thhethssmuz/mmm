#ifndef mmm_swizzle_swizzle_tpp
#define mmm_swizzle_swizzle_tpp

template <typename T, size_t n, size_t... elems>
constexpr swizzle<T, n, elems...>::operator tvec<T, sizeof...(elems)>() const {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  return tvec<T,sizeof...(elems)>(data[elems]...);
}


template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::operator+=(T s) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] += s;
  return *this;
}
template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::
operator+=(const tvec<T, sizeof...(elems)>& u) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] += u[i];
  return *this;
}


template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::operator-=(T s) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] -= s;
  return *this;
}
template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::
operator-=(const tvec<T, sizeof...(elems)>& u) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] -= u[i];
  return *this;
}


template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::operator*=(T s) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] *= s;
  return *this;
}
template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::
operator*=(const tvec<T, sizeof...(elems)>& u) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] *= u[i];
  return *this;
}


template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::operator/=(T s) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] /= s;
  return *this;
}
template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::
operator/=(const tvec<T, sizeof...(elems)>& u) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] /= u[i];
  return *this;
}


template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::operator=(T s) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] = s;
  return *this;
}
template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::
operator=(const swizzle<T, n, elems...>& u) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] = u.data[es[i]];
  return *this;
}
template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::
operator=(const tvec<T, sizeof...(elems)>& u) {
  static_assert(typefu::max<elems...>::value < n,
                "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]] = u[i];
  return *this;
}


template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::operator++() {
  static_assert(typefu::max<elems...>::value < n,
              "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]]++;
  return *this;
}
template <typename T, size_t n, size_t... elems>
tvec<T, sizeof...(elems)> swizzle<T, n, elems...>::operator++(int) {
  static_assert(typefu::max<elems...>::value < n,
              "vector swizzle out of bounds");

  tvec<T, sizeof...(elems)> tmp = *this;
  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]]++;
  return tmp;
}


template <typename T, size_t n, size_t... elems>
swizzle<T, n, elems...>& swizzle<T, n, elems...>::operator--() {
  static_assert(typefu::max<elems...>::value < n,
              "vector swizzle out of bounds");

  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]]--;
  return *this;
}
template <typename T, size_t n, size_t... elems>
tvec<T, sizeof...(elems)> swizzle<T, n, elems...>::operator--(int) {
  static_assert(typefu::max<elems...>::value < n,
              "vector swizzle out of bounds");

  tvec<T, sizeof...(elems)> tmp = *this;
  size_t es[sizeof...(elems)] = {elems...};
  for (size_t i = 0; i < sizeof...(elems); ++i)
    data[es[i]]--;
  return tmp;
}

#endif