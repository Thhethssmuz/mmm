#pragma once

template <typename T, size_t N, typename>
tvec<T, N>& operator++(tvec<T, N>& v) {
  v.recursive.head++;
  v.recursive.tail++;
  return v;
}
template <typename T, size_t N, typename>
tvec<T, N> operator++(tvec<T, N>& v, int) {
  tvec<T, N> tmp = v;
  v.recursive.head++;
  v.recursive.tail++;
  return tmp;
}

template <typename T, size_t N, typename>
tvec<T, N>& operator--(tvec<T, N>& v) {
  v.recursive.head--;
  v.recursive.tail--;
  return v;
}
template <typename T, size_t N, typename>
tvec<T, N> operator--(tvec<T, N>& v, int) {
  tvec<T, N> tmp = v;
  v.recursive.head--;
  v.recursive.tail--;
  return tmp;
}
