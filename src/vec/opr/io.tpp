#pragma once

template <typename T, size_t N, typename A>
std::ostream& operator<<(std::ostream& os, const vecType<T, N, A>& v) {
  return os << vec_cast(v);
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const tvec<T, N>& v) {
  os << "[" << v.data[0];
  for (size_t i = 1; i < N; ++i)
    os << ", " << v.data[i];
  os << "]";
  return os;
}
