#pragma once

template <typename T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& os, const tmat<T, N, M>& m) {
  for (size_t i = 0; i < M; ++i) {
    os << "[" << m.data[0][i];
    for (size_t j = 1; j < N; ++j)
      os << ", " << m.data[j][i];
    os << "]";
    if (i < M - 1)
      os << std::endl;
  }
  return os;
}
