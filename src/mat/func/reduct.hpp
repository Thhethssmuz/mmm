#ifndef mmm_mat_func_reduct_hpp
#define mmm_mat_func_reduct_hpp

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R >= 2>, typename = typefu::for_<R <= M>>
constexpr tmat<T, N, R> takeRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t M, typename = typefu::for_<R >= 2>,
          typename = typefu::for_<R <= M>>
constexpr tmat<T, 2, R> takeRows(const tmat<T, 2, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<R == 1>>
constexpr tvec<T, N> takeRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t M, typename = typefu::for_<R == 1>>
constexpr tvec<T, 2> takeRows(const tmat<T, 2, M>& m);


template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<M - R >= 2>, typename = typefu::for_<R >= 0>>
constexpr tmat<T, N, M - R> dropRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t M, typename = typefu::for_<M - R >= 2>,
          typename = typefu::for_<R >= 0>>
constexpr tmat<T, 2, M - R> dropRows(const tmat<T, 2, M>& m);

template <size_t R, typename T, size_t N, size_t M,
          typename = typefu::for_<M - R == 1>>
constexpr tvec<T, N> dropRows(const tmat<T, N, M>& m);

template <size_t R, typename T, size_t M, typename = typefu::for_<M - R == 1>>
constexpr tvec<T, 2> dropRows(const tmat<T, 2, M>& m);


template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C >= 2>, typename = typefu::for_<(C < N)>>
constexpr tmat<T, C, M> takeColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C == N>>
constexpr tmat<T, N, M> takeColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C == 1>>
constexpr tvec<T, M> takeColumns(const tmat<T, N, M>& m);


template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<N - C >= 2>, typename = typefu::for_<C >= 2>>
constexpr tmat<T, N - C, M> dropColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C == 1>>
constexpr tmat<T, N - C, M> dropColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<C == 0>>
constexpr tmat<T, N, M> dropColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t N, size_t M,
          typename = typefu::for_<N - C == 1>, typename = typefu::for_<C >= 2>>
constexpr tvec<T, M> dropColumns(const tmat<T, N, M>& m);

template <size_t C, typename T, size_t M, typename = typefu::for_<C == 1>>
constexpr tvec<T, M> dropColumns(const tmat<T, 2, M>& m);

#endif