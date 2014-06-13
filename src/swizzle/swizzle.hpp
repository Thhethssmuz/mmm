#ifndef mmm_swizzle_swizzle_hpp
#define mmm_swizzle_swizzle_hpp

template <typename T, size_t N, typename A>
struct vecType;

template <typename T, size_t N>
struct tvec;

template <typename T, size_t N, size_t... Elems>
struct swizzle : vecType<T, sizeof...(Elems), swizzle<T, N, Elems...>> {

  T data[N];

  constexpr operator tvec<T, sizeof...(Elems)>() const;

  swizzle<T, N, Elems...>& operator+=(T s);
  swizzle<T, N, Elems...>& operator+=(const tvec<T, sizeof...(Elems)>& u);
  swizzle<T, N, Elems...>& operator-=(T s);
  swizzle<T, N, Elems...>& operator-=(const tvec<T, sizeof...(Elems)>& u);
  swizzle<T, N, Elems...>& operator*=(T s);
  swizzle<T, N, Elems...>& operator*=(const tvec<T, sizeof...(Elems)>& u);
  swizzle<T, N, Elems...>& operator/=(T s);
  swizzle<T, N, Elems...>& operator/=(const tvec<T, sizeof...(Elems)>& u);

  swizzle<T, N, Elems...>& operator=(T s);
  swizzle<T, N, Elems...>& operator=(const swizzle<T, N, Elems...>& u);
  swizzle<T, N, Elems...>& operator=(const tvec<T, sizeof...(Elems)>& u);

  swizzle<T, N, Elems...>& operator++();
  tvec<T, sizeof...(Elems)> operator++(int);
  swizzle<T, N, Elems...>& operator--();
  tvec<T, sizeof...(Elems)> operator--(int);
};

#endif