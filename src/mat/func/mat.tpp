#pragma once

template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> matrixCompMult(const tmat<T, N, M>& m,
                                       const tmat<T, N, M>& n) {
  return tmat<T, N, M>(m.recursive.head * n.recursive.head,
                       matrixCompMult(m.recursive.tail, n.recursive.tail));
}
template <typename T, size_t N, typename>
constexpr tmat<T, N, 2> matrixCompMult(const tmat<T, N, 2>& m,
                                       const tmat<T, N, 2>& n) {
  return tmat<T, N, 2>(m.recursive.head * n.recursive.head,
                       m.recursive.tail * n.recursive.tail);
}


template <typename T, size_t N, typename>
constexpr tvec<T, N> outerProduct(T c, const tvec<T, N>& r) {
  return c * r;
}
template <typename T, typename U, size_t N, typename A, typename>
constexpr tvec<T, N> outerProduct(U c, const vecType<T, N, A>& r) {
  return outerProduct(static_cast<T>(c), vec_cast(r));
}
template <typename T, size_t M, typename>
constexpr tvec<T, M> outerProduct(const tvec<T, M>& c, T r) {
  return c * r;
}
template <typename T, typename U, size_t M, typename A, typename>
constexpr tvec<T, M> outerProduct(const vecType<T, M, A>& c, U r) {
  return outerProduct(vec_cast(c), static_cast<T>(r));
}
template <typename T, size_t N, size_t M, typename>
constexpr tmat<T, N, M> outerProduct(const tvec<T, M>& c, const tvec<T, N>& r) {
  return tmat<T, N, M>(c.recursive.head * r, outerProduct(c.recursive.tail, r));
}
template <typename T, size_t N, size_t M, typename A, typename B, typename>
constexpr tmat<T, N, M> outerProduct(const vecType<T, M, A>& c,
                                     const vecType<T, N, B>& r) {
  return outerProduct(vec_cast(c), vec_cast(r));
}


template <typename T, size_t N, size_t M>
constexpr tmat<T, M, N> transpose(const tmat<T, N, M>& m) {
  return tmat<T, M, N>(takeColumns<1>(m), transpose(dropColumns<1>(m)));
}
template <typename T, size_t N>
constexpr tvec<T, N> transpose(const tvec<T, N>& v) {
  return v;
}


template <typename T, typename>
constexpr T determinant(const tmat<T, 2, 2>& m) {
  return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}
template <size_t L, typename T, size_t N, typename, typename, typename>
constexpr T determinant(const tmat<T, N, N>& m) {
  return m[0][L] * cofactor<0, L>(m) + determinant<L + 1>(m);
}
template <size_t L, typename T, size_t N, typename, typename>
constexpr T determinant(const tmat<T, N, N>& m) {
  return m[0][L] * cofactor<0, L>(m);
}


template <size_t R, size_t C, typename T, typename, typename>
constexpr T cofactor(const tmat<T, 2, 2>& m) {
  return (mod(R + C, 2) == 0 ? T(1) : T(-1)) * m[1 - R][1 - C];
}
template <size_t R, size_t C, typename T, size_t N, typename, typename>
constexpr T cofactor(const tmat<T, N, N>& m) {
  return (mod(R + C, 2) == 0 ? T(1) : T(-1)) *
         determinant(dropColumn<C>(dropRow<R>(m)));
}


template <typename T, typename>
constexpr tmat<T, 2, 2> cofactors(const tmat<T, 2, 2>& m) {
  return tmat<T, 2, 2>(tvec<T, 2>(m[1][1], -m[1][0]),
                       tvec<T, 2>(-m[0][1], m[0][0]));
}
template <size_t R, typename T, size_t N, typename, typename, typename>
constexpr tmat<T, N, N - R> cofactors(const tmat<T, N, N>& m) {
  return tmat<T, N, N - R>(cofactors<R, 0>(m), cofactors<R + 1>(m));
}
template <size_t R, typename T, size_t N, typename, typename>
constexpr tmat<T, N, 2> cofactors(const tmat<T, N, N>& m) {
  return tmat<T, N, 2>(cofactors<R, 0>(m), cofactors<R + 1, 0>(m));
}
template <size_t R, size_t C, typename T, size_t N, typename, typename,
          typename>
constexpr tvec<T, N - C> cofactors(const tmat<T, N, N>& m) {
  return tvec<T, N - C>(cofactor<R, C>(m), cofactors<R, C + 1>(m));
}
template <size_t R, size_t C, typename T, size_t N, typename, typename>
constexpr tvec<T, 2> cofactors(const tmat<T, N, N>& m) {
  return tvec<T, 2>(cofactor<R, C>(m), cofactor<R, C + 1>(m));
}


template <typename T, size_t N, typename>
constexpr tmat<T, N, N> adjugate(const tmat<T, N, N>& m) {
  return transpose(cofactors(m));
}


template <typename T, size_t N, typename>
constexpr tmat<T, N, N> inverse(const tmat<T, N, N>& m) {
  return T(1) / determinant(m) * adjugate(m);
}
