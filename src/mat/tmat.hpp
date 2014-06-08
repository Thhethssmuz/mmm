#ifndef mmm_mat_tmat_hpp
#define mmm_mat_tmat_hpp

// matrix with n columns and m rows
template <typename T, size_t n, size_t m>
struct tmat {

  static_assert(n > 0 and n > 0, "matrices must have at least 1 elements");

  struct R {
    tvec<T,n>     head;
    tmat<T,n,m-1> tail;
  };

  union {
    tvec<T,m> data[n];
    R         recursive;
  };

           constexpr tmat ();
  explicit constexpr tmat (T x);

  template <typename...Ts, typename...Us, typename = typename
  std::enable_if<detail::vec_components<Ts...>::value == n>::type>
  explicit constexpr tmat (Ts...xs, Us...ys);

  constexpr tvec<T,n>  operator [] (size_t i);
            tvec<T,n>& operator [] (size_t i);
                       operator T* ();

  tmat<T,n,m>& operator += (T s);
  tmat<T,n,m>& operator += (const tmat<T,n,m>& y);
  tmat<T,n,m>& operator -= (T s);
  tmat<T,n,m>& operator -= (const tmat<T,n,m>& y);
  tmat<T,n,m>& operator *= (T s);
  tmat<T,n,m>& operator *= (const tmat<T,n,m>& y);
  tmat<T,n,m>& operator /= (T s);
  tmat<T,n,m>& operator /= (const tmat<T,n,m>& y);

  tmat<T,n,m>& identity  ();
  tmat<T,n,m>& transpose ();
  tmat<T,n,m>& inverse   ();
};

template <typename T, size_t n, size_t m>
template <typename...Ts, typename...Us, typename>
constexpr tmat<T,n,m>::tmat (Ts...xs, Us...ys) : recursive{tvec<T,n>(xs...), tmat<T,n,m-1>(ys...)} {}

template <typename T, size_t n, size_t m>
constexpr tmat<T,n-1,m-1> minor (const tmat<T,m,n>& x, size_t column, size_t row) {
  static_assert (m != n, "minor matrix not defined for non square matrices")
  return remove_row (remove_column (x, column), row);
}




#endif