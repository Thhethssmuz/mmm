#pragma once

template <typename T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& os, const tmat<T, N, M>& m) {
  for (size_t i = 0; i < N; ++i)
    os << m.data[i] << std::endl;
  return os;
}
