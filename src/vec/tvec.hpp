#ifndef mmm_vec_tvec_hpp
#define mmm_vec_tvec_hpp

template <typename T, size_t n, typename A>
struct vecType;

template <typename T, size_t n>
struct tvec : vecType<T, n, tvec<T, n>> {

  static_assert(n > 1, "vectors must have at least 2 elements");

  struct R {
    T head;
    tvec<T, n - 1> tail;
  };

  union {
    T data[n];
    R recursive;

#include <swizzle/swizzle_declarations.tpp>
  };

  constexpr tvec();
  explicit constexpr tvec(T x);
  explicit constexpr tvec(T x, tvec<T, n - 1>&& xs);
  explicit constexpr tvec(T x, const tvec<T, n - 1>& xs);

  constexpr tvec(tvec<T, n>&& v);
  constexpr tvec(const tvec<T, n>& v);


  template <typename... Ts, typename = typefu::for_components<n, T, Ts...>>
  explicit constexpr tvec(T x, Ts... xs);

  template <size_t l, typename... Ts,
            typename = typefu::for_components<n, tvec<T, l>, Ts...>>
  explicit constexpr tvec(const tvec<T, l>& xs, Ts... ys);

  template <size_t l, size_t... elems, typename... Ts,
            typename =
              typefu::for_components<n, swizzle<T, l, elems...>, Ts...>>
  explicit constexpr tvec(const swizzle<T, l, elems...>& xs, Ts... ys);


  constexpr T operator[](size_t i) const;
  T& operator[](size_t i);
  operator T*();

  tvec<T, n>& operator=(const tvec<T, n>& v);

  template <size_t... elems>
  swizzle<T, n, elems...>& swizzleElems();

  template <size_t start, size_t end>
  typefu::swizzle_range<T, n, start, end>& swizzleRange();
};

#endif