#ifndef mmm_vec_tvec2_hpp
#define mmm_vec_tvec2_hpp

template <typename T>
struct tvec<T, 2> : vecType<T, 2, tvec<T, 2>> {

  struct R {
    T head;
    T tail;
  };

  union {
    T data[2];
    R recursive;

#define n 2
#include <swizzle/swizzle_declarations.tpp>
#undef n
  };

  constexpr tvec();
  explicit constexpr tvec(T x);
  explicit constexpr tvec(T x, T y);

  constexpr tvec(tvec<T, 2>&& v);
  constexpr tvec(const tvec<T, 2>& v);


  template <typename... Ts>
  explicit constexpr tvec(T x, T y, Ts...);

  template <size_t l, typename... Ts>
  explicit constexpr tvec(T x, const tvec<T, l>& xs, Ts...);

  template <size_t l, size_t elem, size_t... elems, typename... Ts>
  explicit constexpr tvec(T x, const swizzle<T, l, elem, elems...>& xs, Ts...);

  template <size_t l, typename... Ts>
  explicit constexpr tvec(const tvec<T, l>& xs, Ts...);

  template <size_t l, size_t... elems, typename... Ts>
  explicit constexpr tvec(const swizzle<T, l, elems...>& xs, Ts... ys);


  constexpr T operator[](size_t i) const;
  T& operator[](size_t i);
  operator T*();

  tvec<T, 2>& operator=(const tvec<T, 2>& v);
};

#endif