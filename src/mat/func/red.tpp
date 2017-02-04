#pragma once

template <size_t R, typename T, size_t N, size_t M, typename, typename,
          typename>
constexpr tvec<T, N> takeRow(const tmat<T, N, M>& m) {
  return takeRow<R - 1>(m.recursive.tail);
}
template <size_t R, typename T, size_t N, size_t M, typename, typename>
constexpr tvec<T, N> takeRow(const tmat<T, N, M>& m) {
  return m.recursive.tail;
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tvec<T, N> takeRow(const tmat<T, N, M>& m) {
  return m.recursive.head;
}


template <size_t R, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N, R> takeRows(const tmat<T, N, M>& m) {
  return tmat<T, N, R>(m.recursive.head, takeRows<R - 1>(m.recursive.tail));
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, R> takeRows(const tmat<T, N, M>& m) {
  return m;
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tvec<T, N> takeRows(const tmat<T, N, M>& m) {
  return m.recursive.head;
}


template <size_t R, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N, M - 1> dropRow(const tmat<T, N, M>& m) {
  return tmat<T, N, M - 1>(m.recursive.head, dropRow<R - 1>(m.recursive.tail));
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M - 1> dropRow(const tmat<T, N, M>& m) {
  return m.recursive.tail;
}
template <size_t R, typename T, size_t N, typename, typename>
constexpr tvec<T, N> dropRow(const tmat<T, N, 2>& m) {
  return m.recursive.head;
}
template <size_t R, typename T, size_t N, typename>
constexpr tvec<T, N> dropRow(const tmat<T, N, 2>& m) {
  return m.recursive.tail;
}


template <size_t R, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N, M - R> dropRows(const tmat<T, N, M>& m) {
  return dropRows<R - 1>(m.recursive.tail);
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M - R> dropRows(const tmat<T, N, M>& m) {
  return m.recursive.tail;
}
template <size_t R, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> dropRows(const tmat<T, N, M>& m) {
  return m;
}
template <size_t R, typename T, size_t N, size_t M, typename, typename>
constexpr tvec<T, N> dropRows(const tmat<T, N, M>& m) {
  return dropRows<R - 1>(m.recursive.tail);
}
template <size_t R, typename T, size_t N, typename>
constexpr tvec<T, N> dropRows(const tmat<T, N, 2>& m) {
  return m.recursive.tail;
}


template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tvec<T, M> takeColumn(const tmat<T, N, M>& m) {
  return tvec<T, M>(m.recursive.head.data[C], takeColumn<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, typename>
constexpr tvec<T, 2> takeColumn(const tmat<T, N, 2>& m) {
  return tvec<T, 2>(m.recursive.head.data[C], m.recursive.tail.data[C]);
}


template <size_t C, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, C, M> takeColumns(const tmat<T, N, M>& m) {
  return tmat<T, C, M>(take<C>(m.recursive.head),
                       takeColumns<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, typename, typename>
constexpr tmat<T, C, 2> takeColumns(const tmat<T, N, 2>& m) {
  return tmat<T, C, 2>(take<C>(m.recursive.head), take<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tvec<T, M> takeColumns(const tmat<T, N, M>& m) {
  return tvec<T, M>(take<C>(m.recursive.head),
                    takeColumns<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, typename>
constexpr tvec<T, 2> takeColumns(const tmat<T, N, 2>& m) {
  return tvec<T, 2>(take<C>(m.recursive.head), take<C>(m.recursive.tail));
}


template <size_t C, typename T, size_t N, size_t M, typename, typename,
          typename>
constexpr tmat<T, N - 1, M> dropColumn(const tmat<T, N, M>& m) {
  return tmat<T, N - 1, M>(
    tvec<T, N - 1>(take<C>(m.recursive.head), drop<C + 1>(m.recursive.head)),
    dropColumn<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, size_t M, typename, typename>
constexpr tmat<T, N - 1, M> dropColumn(const tmat<T, N, M>& m) {
  return tmat<T, N - 1, M>(drop<C + 1>(m.recursive.head),
                           dropColumn<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N - 1, M> dropColumn(const tmat<T, N, M>& m) {
  return tmat<T, N - 1, M>(take<C>(m.recursive.head),
                           dropColumn<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t M, typename, typename>
constexpr tvec<T, M> dropColumn(const tmat<T, 2, M>& m) {
  return tvec<T, M>(m.recursive.head.recursive.tail,
                    dropColumn<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t M, typename>
constexpr tvec<T, M> dropColumn(const tmat<T, 2, M>& m) {
  return tvec<T, M>(m.recursive.head.recursive.head,
                    dropColumn<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, typename, typename, typename>
constexpr tmat<T, N - 1, 2> dropColumn(const tmat<T, N, 2>& m) {
  return tmat<T, N - 1, 2>(
    tvec<T, N - 1>(take<C>(m.recursive.head), drop<C + 1>(m.recursive.head)),
    tvec<T, N - 1>(take<C>(m.recursive.tail), drop<C + 1>(m.recursive.tail)));
}
template <size_t C, typename T, size_t N, typename, typename>
constexpr tmat<T, N - 1, 2> dropColumn(const tmat<T, N, 2>& m) {
  return tmat<T, N - 1, 2>(drop<C + 1>(m.recursive.head),
                           drop<C + 1>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, typename>
constexpr tmat<T, N - 1, 2> dropColumn(const tmat<T, N, 2>& m) {
  return tmat<T, N - 1, 2>(take<C>(m.recursive.head),
                           take<C>(m.recursive.tail));
}
template <size_t C, typename T, typename, typename>
constexpr tvec<T, 2> dropColumn(const tmat<T, 2, 2>& m) {
  return tvec<T, 2>(m.recursive.head.recursive.tail,
                    m.recursive.tail.recursive.tail);
}
template <size_t C, typename T, typename>
constexpr tvec<T, 2> dropColumn(const tmat<T, 2, 2>& m) {
  return tvec<T, 2>(m.recursive.head.recursive.head,
                    m.recursive.tail.recursive.head);
}

template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tmat<T, N - C, M> dropColumns(const tmat<T, N, M>& m) {
  return tmat<T, N - C, M>(drop<C>(m.recursive.head),
                           dropColumns<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, typename>
constexpr tmat<T, N - C, 2> dropColumns(const tmat<T, N, 2>& m) {
  return tmat<T, N - C, 2>(drop<C>(m.recursive.head),
                           drop<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, size_t M, typename>
constexpr tvec<T, M> dropColumns(const tmat<T, N, M>& m) {
  return tvec<T, M>(drop<C>(m.recursive.head),
                    dropColumns<C>(m.recursive.tail));
}
template <size_t C, typename T, size_t N, typename>
constexpr tvec<T, 2> dropColumns(const tmat<T, N, 2>& m) {
  return tvec<T, 2>(drop<C>(m.recursive.head), drop<C>(m.recursive.tail));
}
