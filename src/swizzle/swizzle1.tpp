#ifndef mmm_swizzle_swizzle1_tpp
#define mmm_swizzle_swizzle1_tpp

template <typename T, size_t n, size_t a>
constexpr swizzle<T, n, a>::operator T() const {
  static_assert(a < n, "vector swizzle out of bounds");
  return data[a];
}


template <typename T, size_t n, size_t a>
swizzle<T, n, a>::operator T&() {
  static_assert(a < n, "vector swizzle out of bounds");
  return data[a];
}


template <typename T, size_t n, size_t a>
T* swizzle<T, n, a>::operator&() {
  static_assert(a < n, "vector swizzle out of bounds");
  return &data[a];
}


template <typename T, size_t n, size_t a>
T& swizzle<T, n, a>::operator=(T x) {
  static_assert(a < n, "vector swizzle out of bounds");
  return data[a] = x;
}
template <typename T, size_t n, size_t a>
T& swizzle<T, n, a>::operator=(const swizzle<T, n, a>& x) {
  static_assert(a < n, "vector swizzle out of bounds");
  return data[a] = x.data[a];
}

#endif