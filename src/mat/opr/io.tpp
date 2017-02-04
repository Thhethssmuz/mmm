#pragma once

template <typename T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& os, const tmat<T, N, M>& m) {
  os << "[";
  os << m.data[0];
  for (size_t i = 1; i < M; ++i)
    os << ", " << m.data[i];
  os << "]";
  return os;
}
