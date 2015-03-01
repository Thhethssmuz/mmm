#pragma once

template <typename T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& os, const tmat<T, N, M>& m);
