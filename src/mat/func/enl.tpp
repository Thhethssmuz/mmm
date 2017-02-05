#pragma once

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M + 1> appendRow(const tmat<T, N, M>& m,
                                      const tvec<T, N>& n) {
  return tmat<T, N, M + 1>(m, n);
}


template <typename T, size_t N, size_t M>
constexpr tmat<T, N + 1, M> appendColumn(const tmat<T, N, M>& m,
                                         const tvec<T, M>& n) {
  return tmat<T, N + 1, M>(tvec<T, N + 1>(m.recursive.head, n.recursive.head),
                           appendColumn(m.recursive.tail, n.recursive.tail));
}
template <typename T, size_t N>
constexpr tmat<T, N + 1, 2> appendColumn(const tmat<T, N, 2>& m,
                                         const tvec<T, 2>& n) {
  return tmat<T, N + 1, 2>(tvec<T, N + 1>(m.recursive.head, n.recursive.head),
                           tvec<T, N + 1>(m.recursive.tail, n.recursive.tail));
}
