#pragma once

template <typename T, size_t N, size_t M>
constexpr tmat<T, N, M + 1> appendRow(const tmat<T, N, M>& m,
                                      const tvec<T, N>& n);


template <typename T, size_t N, size_t M>
constexpr tmat<T, N + 1, M> appendColumn(const tmat<T, N, M>& m,
                                         const tvec<T, M>& n);

template <typename T, size_t N>
constexpr tmat<T, N + 1, 2> appendColumn(const tmat<T, N, 2>& m,
                                         const tvec<T, 2>& n);
