#ifndef mmm_vec_opr_asig_tpp
#define mmm_vec_opr_asig_tpp

template <typename T, size_t n, typename>
tvec<T, n>& operator+=(tvec<T, n>& v, T s) {
  v.recursive.head += s;
  v.recursive.tail += s;
  return v;
}
template <typename T, typename U, size_t n, typename>
tvec<T, n>& operator+=(tvec<T, n>& v, U s) {
  return v += static_cast<T>(s);
}
template <typename T, size_t n, typename>
tvec<T, n>& operator+=(tvec<T, n>& v, const tvec<T, n>& u) {
  v.recursive.head += u.recursive.head;
  v.recursive.tail += u.recursive.tail;
  return v;
}
template <typename T, size_t n, typename A, typename>
tvec<T, n>& operator+=(tvec<T, n>& v, const vecType<T, n, A>& u) {
  return v += vec_cast(u);
}


template <typename T, size_t n, typename>
tvec<T, n>& operator-=(tvec<T, n>& v, T s) {
  v.recursive.head -= s;
  v.recursive.tail -= s;
  return v;
}
template <typename T, typename U, size_t n, typename>
tvec<T, n>& operator-=(tvec<T, n>& v, U s) {
  return v -= static_cast<T>(s);
}
template <typename T, size_t n, typename>
tvec<T, n>& operator-=(tvec<T, n>& v, const tvec<T, n>& u) {
  v.recursive.head -= u.recursive.head;
  v.recursive.tail -= u.recursive.tail;
  return v;
}
template <typename T, size_t n, typename A, typename>
tvec<T, n>& operator-=(tvec<T, n>& v, const vecType<T, n, A>& u) {
  return v -= vec_cast(u);
}


template <typename T, size_t n, typename>
tvec<T, n>& operator*=(tvec<T, n>& v, T s) {
  v.recursive.head *= s;
  v.recursive.tail *= s;
  return v;
}
template <typename T, typename U, size_t n, typename>
tvec<T, n>& operator*=(tvec<T, n>& v, U s) {
  return v *= static_cast<T>(s);
}
template <typename T, size_t n, typename>
tvec<T, n>& operator*=(tvec<T, n>& v, const tvec<T, n>& u) {
  v.recursive.head *= u.recursive.head;
  v.recursive.tail *= u.recursive.tail;
  return v;
}
template <typename T, size_t n, typename A, typename>
tvec<T, n>& operator*=(tvec<T, n>& v, const vecType<T, n, A>& u) {
  return v *= vec_cast(u);
}


template <typename T, size_t n, typename>
tvec<T, n>& operator/=(tvec<T, n>& v, T s) {
  v.recursive.head /= s;
  v.recursive.tail /= s;
  return v;
}
template <typename T, typename U, size_t n, typename>
tvec<T, n>& operator/=(tvec<T, n>& v, U s) {
  return v /= static_cast<T>(s);
}
template <typename T, size_t n, typename>
tvec<T, n>& operator/=(tvec<T, n>& v, const tvec<T, n>& u) {
  v.recursive.head /= u.recursive.head;
  v.recursive.tail /= u.recursive.tail;
  return v;
}
template <typename T, size_t n, typename A, typename>
tvec<T, n>& operator/=(tvec<T, n>& v, const vecType<T, n, A>& u) {
  return v /= vec_cast(u);
}

#endif