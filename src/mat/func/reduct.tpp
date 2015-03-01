#pragma once

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


template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tvec<T, N> takeRow(const tmat<T, N, M>& m) {
  return tvec<T, N>(m.recursive.head.data[R], takeRow<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t M, typename>
constexpr tvec<T, 2> takeRow(const tmat<T, 2, M>& m) {
  return tvec<T, 2>(m.recursive.head.data[R], m.recursive.tail.data[R]);
}


template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M - R> dropRows(const tmat<T, N, M>& m) {
  return tmat<T, N, M - R>(drop<R>(m.recursive.head),
                           dropRows<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t M, typename>
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


template <size_t R, typename T, size_t N, size_t M, typename, typename,
          typename>
constexpr tmat<T, N, M - 1> dropRow(const tmat<T, N, M>& m) {
  return tmat<T, N, M - 1>(
    tvec<T, M - 1>(take<R>(m.recursive.head), drop<R + 1>(m.recursive.head)),
    dropRow<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N, M - 1> dropRow(const tmat<T, N, M>& m) {
  return tmat<T, N, M - 1>(drop<R + 1>(m.recursive.head),
                           dropRow<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M - 1> dropRow(const tmat<T, N, M>& m) {
  return tmat<T, N, M - 1>(take<R>(m.recursive.head),
                           dropRow<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t N, typename, typename>
constexpr tvec<T, N> dropRow(const tmat<T, N, 2>& m) {
  return tvec<T, N>(m.recursive.head.recursive.tail,
                    dropRow<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t N, typename>
constexpr tvec<T, N> dropRow(const tmat<T, N, 2>& m) {
  return tvec<T, N>(m.recursive.head.recursive.head,
                    dropRow<R>(m.recursive.tail));
}
template <size_t R, typename T, size_t M, typename, typename, typename>
constexpr tmat<T, 2, M - 1> dropRow(const tmat<T, 2, M>& m) {
  return tmat<T, 2, M - 1>(
    tvec<T, M - 1>(take<R>(m.recursive.head), drop<R + 1>(m.recursive.head)),
    tvec<T, M - 1>(take<R>(m.recursive.tail), drop<R + 1>(m.recursive.tail)));
}
template <size_t R, typename T, size_t M, typename, typename>
constexpr tmat<T, 2, M - 1> dropRow(const tmat<T, 2, M>& m) {
  return tmat<T, 2, M - 1>(drop<R + 1>(m.recursive.head),
                           drop<R + 1>(m.recursive.tail));
}
template <size_t R, typename T, size_t M, typename>
constexpr tmat<T, 2, M - 1> dropRow(const tmat<T, 2, M>& m) {
  return tmat<T, 2, M - 1>(take<R>(m.recursive.head),
                           take<R>(m.recursive.tail));
}
template <size_t R, typename T, typename, typename>
constexpr tvec<T, 2> dropRow(const tmat<T, 2, 2>& m) {
  return tvec<T, 2>(m.recursive.head.recursive.tail,
                    m.recursive.tail.recursive.tail);
}
template <size_t R, typename T, typename>
constexpr tvec<T, 2> dropRow(const tmat<T, 2, 2>& m) {
  return tvec<T, 2>(m.recursive.head.recursive.head,
                    m.recursive.tail.recursive.head);
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


template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tvec<T, M> takeColumn(const tmat<T, N, M>& m) {
  return m.data[C];
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


template <size_t C, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N - 1, M> dropColumn(const tmat<T, N, M>& m) {
  return tmat<T, N - 1, M>(m.recursive.head,
                           dropColumn<C - 1>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N - 1, M> dropColumn(const tmat<T, N, M>& m) {
  return m.recursive.tail;
}
template <size_t C, typename T, size_t M, typename, typename>
constexpr tvec<T, M> dropColumn(const tmat<T, 2, M>& m) {
  return m.recursive.head;
}
template <size_t C, typename T, size_t M, typename>
constexpr tvec<T, M> dropColumn(const tmat<T, 2, M>& m) {
  return m.recursive.tail;
}
