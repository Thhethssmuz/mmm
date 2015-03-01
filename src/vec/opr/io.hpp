#pragma once

template <typename T, size_t N, typename A>
std::ostream& operator<<(std::ostream& os, const vecType<T, N, A>& v);

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const tvec<T, N>& v);
