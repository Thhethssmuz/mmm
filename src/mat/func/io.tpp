#pragma once

template <typename T, size_t N, size_t M>
void print(const tmat<T, N, M>& m) {
  for (size_t i = 0; i < M; ++i)
    print(m.data[i]);
}
