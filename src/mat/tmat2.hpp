#ifndef mmm_mat_tmat2_hpp
#define mmm_mat_tmat2_hpp

template <typename T, size_t M>
struct tmat<T, 2, M> {

  static_assert(M > 1, "matrices must have at least 2 rows");

  struct R {
    tvec<T, M> head;
    tvec<T, M> tail;
  };

  union {
    tvec<T, M> data[2];
    R recursive;
  };

  constexpr tmat();
  explicit constexpr tmat(T x);
  explicit constexpr tmat(const tvec<T, M>& v, const tvec<T, M>& u);

  constexpr tmat(tmat<T, 2, M>&& m);
  constexpr tmat(const tmat<T, 2, M>& m);

  template <size_t L, typename = typefu::for_<L >= 2 * M>>
  explicit constexpr tmat(const tvec<T, L>& xs);

  template <typename... Ts, typename = typefu::for_components<2 * M, Ts...>>
  explicit constexpr tmat(Ts... xs);

  constexpr tvec<T, M> operator[](size_t i) const;
  tvec<T, M>& operator[](size_t i);
  operator T*();

  tmat<T, 2, M>& operator=(const tmat<T, 2, M>& m);
};

#endif