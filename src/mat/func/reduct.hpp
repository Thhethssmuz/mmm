#pragma once

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<(R > 0)>, typename = typefu::for_<(R < M)>,
          typename = typefu::for_<(M > 2)>>
constexpr tvec<T, N> takeRow(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R == 1>, typename = typefu::for_<M == 2>>
constexpr tvec<T, N> takeRow(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R == 0>>
constexpr tvec<T, N> takeRow(const tmat<T, N, M>& m);


template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<(R > 1)>,
          typename = typefu::for_<(R < M)>>
constexpr tmat<T, N, R> takeRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R == M>>
constexpr tmat<T, N, R> takeRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R == 1>>
constexpr tvec<T, N> takeRows(const tmat<T, N, M>& m);


template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<(R > 0)>, typename = typefu::for_<(R < M)>>
constexpr tmat<T, N, M - 1> dropRow(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R == 0>>
constexpr tmat<T, N, M - 1> dropRow(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, typename = typefu::for_<R == 1>,
          typename = void>
constexpr tvec<T, N> dropRow(const tmat<T, N, 2>& m);

template <size_t R, typename T, size_t N, typename = typefu::for_<R == 0>>
constexpr tvec<T, N> dropRow(const tmat<T, N, 2>& m);


template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<M - R >= 2>, typename = typefu::for_<R >= 2>>
constexpr tmat<T, N, M - R> dropRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R == 1>>
constexpr tmat<T, N, M - R> dropRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R == 0>>
constexpr tmat<T, N, M> dropRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<M - R == 1>, typename = typefu::for_<R >= 2>>
constexpr tvec<T, N> dropRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t N, typename = typefu::for_<R == 1>>
constexpr tvec<T, N> dropRows(const tmat<T, N, 2>& m);


template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<(C < N)>>
constexpr tvec<T, M> takeColumn(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, typename = typefu::for_<(C < N)>>
constexpr tvec<T, 2> takeColumn(const tmat<T, N, 2>& m);


template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C >= 2>, typename = typefu::for_<C <= N>>
constexpr tmat<T, C, M> takeColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, typename = typefu::for_<C >= 2>,
          typename = typefu::for_<C <= N>>
constexpr tmat<T, C, 2> takeColumns(const tmat<T, N, 2>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C == 1>>
constexpr tvec<T, M> takeColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, typename = typefu::for_<C == 1>>
constexpr tvec<T, 2> takeColumns(const tmat<T, N, 2>& m);


template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C != 0>, typename = typefu::for_<C != N - 1>,
          typename = typefu::for_<(C < N)>>
constexpr tmat<T, N - 1, M> dropColumn(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C == 0>, typename = void>
constexpr tmat<T, N - 1, M> dropColumn(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C == N - 1>>
constexpr tmat<T, N - 1, M> dropColumn(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t M, typename = typefu::for_<C == 0>,
          typename = void>
constexpr tvec<T, M> dropColumn(const tmat<T, 2, M>& m);

template <size_t C, typename T, size_t M, typename = typefu::for_<C == 1>>
constexpr tvec<T, M> dropColumn(const tmat<T, 2, M>& m);

template <size_t C, typename T, size_t N, typename = typefu::for_<C != 0>,
          typename = typefu::for_<C != N - 1>, typename = typefu::for_<(C < N)>>
constexpr tmat<T, N - 1, 2> dropColumn(const tmat<T, N, 2>& m);

template <size_t C, typename T, size_t N, typename = typefu::for_<C == 0>,
          typename = void>
constexpr tmat<T, N - 1, 2> dropColumn(const tmat<T, N, 2>& m);

template <size_t C, typename T, size_t N, typename = typefu::for_<C == N - 1>>
constexpr tmat<T, N - 1, 2> dropColumn(const tmat<T, N, 2>& m);

template <size_t C, typename T, typename = typefu::for_<C == 0>,
          typename = void>
constexpr tvec<T, 2> dropColumn(const tmat<T, 2, 2>& m);

template <size_t C, typename T, typename = typefu::for_<C == 1>>
constexpr tvec<T, 2> dropColumn(const tmat<T, 2, 2>& m);


template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<N - C >= 2>>
constexpr tmat<T, N - C, M> dropColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, typename = typefu::for_<N - C >= 2>>
constexpr tmat<T, N - C, 2> dropColumns(const tmat<T, N, 2>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<N - C == 1>>
constexpr tvec<T, M> dropColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, typename = typefu::for_<N - C == 1>>
constexpr tvec<T, 2> dropColumns(const tmat<T, N, 2>& m);
