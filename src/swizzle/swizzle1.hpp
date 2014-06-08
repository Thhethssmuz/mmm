#ifndef mmm_swizzle_swizzle1_hpp
#define mmm_swizzle_swizzle1_hpp

template <typename T, size_t n, size_t a>
struct swizzle<T, n, a> {

  T data[n];

  constexpr operator T() const;
  operator T&();
  T* operator&();

  T& operator=(T x);
  T& operator=(const swizzle<T,n,a>&);
};

#endif