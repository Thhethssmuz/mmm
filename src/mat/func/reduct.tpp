#ifndef mmm_mat_func_reduct_tpp
#define mmm_mat_func_reduct_tpp

template <size_t R, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N, R> takeRows(const tmat<T, N, M>& m) {
  return tmat<T, N, R>(take<R>(m.recursive.head),
                       takeRows<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t M, typename, typename>
constexpr tmat<T, 2, R> takeRows(const tmat<T, 2, M>& m) {
  return tmat<T, 2, R>(take<R>(m.recursive.head), take<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tvec<T, N> takeRows(const tmat<T, N, M>& m) {
  return tvec<T, N>(take<R>(m.recursive.head), takeRows<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t M, typename>
constexpr tvec<T, 2> takeRows(const tmat<T, 2, M>& m) {
  return tvec<T, 2>(take<R>(m.recursive.head), take<R>(m.recursive.tail));
}


template <size_t R, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N, M - R> dropRows(const tmat<T, N, M>& m) {
  return tmat<T, N, M - R>(drop<R>(m.recursive.head),
                           dropRows<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t M, typename, typename>
constexpr tmat<T, 2, M - R> dropRows(const tmat<T, 2, M>& m) {
  return tmat<T, 2, M - R>(drop<R>(m.recursive.head),
                           drop<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tvec<T, N> dropRows(const tmat<T, N, M>& m) {
  return tvec<T, N>(drop<R>(m.recursive.head), dropRows<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t M, typename>
constexpr tvec<T, 2> dropRows(const tmat<T, 2, M>& m) {
  return tvec<T, 2>(drop<R>(m.recursive.head), drop<R>(m.recursive.tail));
}


template <size_t C, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, C, M> takeColumns(const tmat<T, N, M>& m) {
  return tmat<T, C, M>(m.recursive.head, takeColumns<C - 1>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> takeColumns(const tmat<T, N, M>& m) {
  return m;
}
template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tvec<T, M> takeColumns(const tmat<T, N, M>& m) {
  return m.recursive.head;
}


template <size_t C, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N - C, M> dropColumns(const tmat<T, N, M>& m) {
  return dropColumns<C - 1>(m.recursive.tail);
}
template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N - C, M> dropColumns(const tmat<T, N, M>& m) {
  return m.recursive.tail;
}
template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> dropColumns(const tmat<T, N, M>& m) {
  return m;
}
template <size_t C, typename T, size_t N, size_t M, typename, typename>
constexpr tvec<T, M> dropColumns(const tmat<T, N, M>& m) {
  return dropColumns<C - 1>(m.recursive.tail);
}
template <size_t C, typename T, size_t M, typename>
constexpr tvec<T, M> dropColumns(const tmat<T, 2, M>& m) {
  return m.recursive.tail;
}

#endif