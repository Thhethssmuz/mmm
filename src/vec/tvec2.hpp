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

#define N 2
#include <swizzle/swizzle_declarations.tpp>
#undef N
  };

  constexpr tvec();
  explicit constexpr tvec(T x);
  explicit constexpr tvec(T x, T y);

  constexpr tvec(tvec<T, 2>&& v);
  constexpr tvec(const tvec<T, 2>& v);


  template <typename U, typename = typefu::for_convertible<T, U>>
  explicit constexpr tvec(const tvec<U, 2>& v);

  template <typename U, typename A, typename = typefu::for_convertible<T, U>>
  explicit constexpr tvec(const vecType<U, 2, A>& v);


  template <typename... Ts>
  explicit constexpr tvec(T x, T y, Ts...);

  template <size_t L, typename... Ts>
  explicit constexpr tvec(T x, const tvec<T, L>& xs, Ts...);

  template <size_t L, size_t Elem, size_t... Elems, typename... Ts>
  explicit constexpr tvec(T x, const swizzle<T, L, Elem, Elems...>& xs, Ts...);

  template <size_t L, size_t K, typename... Ts>
  explicit constexpr tvec(T x, const tmat<T, L, K>& xs, Ts... ys);

  template <size_t L, typename... Ts>
  explicit constexpr tvec(const tvec<T, L>& xs, Ts...);

  template <size_t L, size_t... Elems, typename... Ts>
  explicit constexpr tvec(const swizzle<T, L, Elems...>& xs, Ts... ys);

  template <size_t L, size_t K, typename... Ts>
  explicit constexpr tvec(const tmat<T, L, K>& xs, Ts... ys);


  constexpr T operator[](size_t i) const;
  T& operator[](size_t i);
  operator T*();

  tvec<T, 2>& operator=(const tvec<T, 2>& v);
};

#endif