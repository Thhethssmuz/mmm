#ifndef mmm_swizzle_swizzle_hpp
#define mmm_swizzle_swizzle_hpp

template <typename T, size_t n, typename A>
struct vecType;

template <typename T, size_t n>
struct tvec;

template <typename T, size_t n, size_t... elems>
struct swizzle : vecType<T, sizeof...(elems), swizzle<T, n, elems...>> {

  T data[n];

  constexpr operator tvec<T, sizeof...(elems)>() const;

  swizzle<T, n, elems...>& operator+=(T s);
  swizzle<T, n, elems...>& operator+=(const tvec<T, sizeof...(elems)>& u);
  swizzle<T, n, elems...>& operator-=(T s);
  swizzle<T, n, elems...>& operator-=(const tvec<T, sizeof...(elems)>& u);
  swizzle<T, n, elems...>& operator*=(T s);
  swizzle<T, n, elems...>& operator*=(const tvec<T, sizeof...(elems)>& u);
  swizzle<T, n, elems...>& operator/=(T s);
  swizzle<T, n, elems...>& operator/=(const tvec<T, sizeof...(elems)>& u);

  swizzle<T, n, elems...>& operator=(T s);
  swizzle<T, n, elems...>& operator=(const swizzle<T, n, elems...>& u);
  swizzle<T, n, elems...>& operator=(const tvec<T, sizeof...(elems)>& u);

  swizzle<T, n, elems...>& operator++();
  tvec<T, sizeof...(elems)> operator++(int);
  swizzle<T, n, elems...>& operator--();
  tvec<T, sizeof...(elems)> operator--(int);
};

#endif