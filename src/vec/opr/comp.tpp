#ifndef mmm_vec_opr_comp_tpp
#define mmm_vec_opr_comp_tpp


template <typename T, size_t N, typename>
constexpr bool operator<(T s, const tvec<T, N>& v) {
  return s < v.recursive.head and s < v.recursive.tail;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator<(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) < vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr bool operator<(const tvec<T, N>& v, T s) {
  return v.recursive.head < s and v.recursive.tail < s;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator<(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) < static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr bool operator<(const tvec<T, N>& v, const tvec<T, N>& u) {
  return v.recursive.head < u.recursive.head and v.recursive.tail <
         u.recursive.tail;
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr bool operator<(const vecType<T, N, A>& v, const vecType<T, N, B>& u) {
  return vec_cast(v) < vec_cast(u);
}


template <typename T, size_t N, typename>
constexpr bool operator<=(T s, const tvec<T, N>& v) {
  return s <= v.recursive.head and s <= v.recursive.tail;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator<=(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) <= vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr bool operator<=(const tvec<T, N>& v, T s) {
  return v.recursive.head <= s and v.recursive.tail <= s;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator<=(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) <= static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr bool operator<=(const tvec<T, N>& v, const tvec<T, N>& u) {
  return v.recursive.head <= u.recursive.head and v.recursive.tail <=
         u.recursive.tail;
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr bool operator<=(const vecType<T, N, A>& v,
                          const vecType<T, N, B>& u) {
  return vec_cast(v) <= vec_cast(u);
}


template <typename T, size_t N, typename>
constexpr bool operator>=(T s, const tvec<T, N>& v) {
  return s >= v.recursive.head and s >= v.recursive.tail;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator>=(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) >= vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr bool operator>=(const tvec<T, N>& v, T s) {
  return v.recursive.head >= s and v.recursive.tail >= s;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator>=(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) >= static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr bool operator>=(const tvec<T, N>& v, const tvec<T, N>& u) {
  return v.recursive.head >= u.recursive.head and v.recursive.tail >=
         u.recursive.tail;
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr bool operator>=(const vecType<T, N, A>& v,
                          const vecType<T, N, B>& u) {
  return vec_cast(v) >= vec_cast(u);
}


template <typename T, size_t N, typename>
constexpr bool operator>(T s, const tvec<T, N>& v) {
  return s > v.recursive.head and s > v.recursive.tail;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator>(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) > vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr bool operator>(const tvec<T, N>& v, T s) {
  return v.recursive.head > s and v.recursive.tail > s;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator>(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) > static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr bool operator>(const tvec<T, N>& v, const tvec<T, N>& u) {
  return v.recursive.head > u.recursive.head and v.recursive.tail >
         u.recursive.tail;
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr bool operator>(const vecType<T, N, A>& v, const vecType<T, N, B>& u) {
  return vec_cast(v) > vec_cast(u);
}


template <typename T, size_t N, typename>
constexpr bool operator==(T s, const tvec<T, N>& v) {
  return s == v.recursive.head and s == v.recursive.tail;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator==(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) == vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr bool operator==(const tvec<T, N>& v, T s) {
  return v.recursive.head == s and v.recursive.tail == s;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator==(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) == static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr bool operator==(const tvec<T, N>& v, const tvec<T, N>& u) {
  return v.recursive.head == u.recursive.head and v.recursive.tail ==
         u.recursive.tail;
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr bool operator==(const vecType<T, N, A>& v,
                          const vecType<T, N, B>& u) {
  return vec_cast(v) == vec_cast(u);
}


template <typename T, size_t N, typename>
constexpr bool operator!=(T s, const tvec<T, N>& v) {
  return s != v.recursive.head or s != v.recursive.tail;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator!=(U s, const vecType<T, N, A>& v) {
  return static_cast<T>(s) != vec_cast(v);
}
template <typename T, size_t N, typename>
constexpr bool operator!=(const tvec<T, N>& v, T s) {
  return v.recursive.head != s or v.recursive.tail != s;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr bool operator!=(const vecType<T, N, A>& v, U s) {
  return vec_cast(v) != static_cast<T>(s);
}
template <typename T, size_t N, typename>
constexpr bool operator!=(const tvec<T, N>& v, const tvec<T, N>& u) {
  return v.recursive.head != u.recursive.head or v.recursive.tail !=
         u.recursive.tail;
}
template <typename T, size_t N, typename A, typename B, typename>
constexpr bool operator!=(const vecType<T, N, A>& v,
                          const vecType<T, N, B>& u) {
  return vec_cast(v) != vec_cast(u);
}

#endif