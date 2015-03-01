#pragma once

template <typename T, size_t N, size_t M>
void print(const tmat<T, N, M>& m) {
  for (size_t i = 0; i < M; ++i) {
    std::cout << "[" << m.data[0][i];
    for (size_t j = 1; j < N; ++j)
      std::cout << ", " << m.data[j][i];
    std::cout << "]" << std::endl;
  }
}
