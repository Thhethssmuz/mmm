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

  constexpr T operator[](size_t i) const;
  T& operator[](size_t i);
  operator T*();

  tvec<T, 2>& operator=(const tvec<T, 2>& v);
};

#endif