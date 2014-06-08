#ifndef mmm_vec_tvec2_tpp
#define mmm_vec_tvec2_tpp

template <typename T>
constexpr tvec<T, 2>::tvec()
  : data{0} {}

template <typename T>
constexpr tvec<T, 2>::tvec(T x, T y)
  : data{x, y} {}

template <typename T>
constexpr tvec<T, 2>::tvec(T x)
  : data{x, x} {}


template <typename T>
constexpr T tvec<T, 2>::operator[](size_t i) const {
  return data[i];
}

template <typename T>
T& tvec<T, 2>::operator[](size_t i) {
  return data[i];
}


template <typename T>
tvec<T, 2>::operator T*() {
  return data;
}

#endif