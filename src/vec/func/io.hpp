#pragma once

template <typename T, size_t N>
void print(const tvec<T, N>& v);

template <typename T, size_t N, typename A>
void print(const vecType<T, N, A>& v);
