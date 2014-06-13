#ifndef mmm_swizzle_swizzle1_tpp
#define mmm_swizzle_swizzle1_tpp

template <typename T, size_t N, size_t A>
constexpr swizzle<T, N, A>::operator T() const {
  static_assert(A < N, "vector swizzle out of bounds");
  return data[A];
}


template <typename T, size_t N, size_t A>
swizzle<T, N, A>::operator T&() {
  static_assert(A < N, "vector swizzle out of bounds");
  return data[A];
}


template <typename T, size_t N, size_t A>
T* swizzle<T, N, A>::operator&() {
  static_assert(A < N, "vector swizzle out of bounds");
  return &data[A];
}


template <typename T, size_t N, size_t A>
T& swizzle<T, N, A>::operator=(T x) {
  static_assert(A < N, "vector swizzle out of bounds");
  return data[A] = x;
}
template <typename T, size_t N, size_t A>
T& swizzle<T, N, A>::operator=(const swizzle<T, N, A>& x) {
  static_assert(A < N, "vector swizzle out of bounds");
  return data[A] = x.data[A];
}

#endif