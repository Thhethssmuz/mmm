#pragma once

// prints matrix to stdout in column-major order
template <typename T, size_t N, size_t M>
void print(const tmat<T, N, M>& m);
