#pragma once

template <typename T, size_t N, size_t A>
struct swizzle<T, N, A> {

  T data[N];

  constexpr operator T() const;
  operator T&();
  T* operator&();

  T& operator=(T x);
  T& operator=(const swizzle<T,N,A>&);
};
