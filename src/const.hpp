#pragma once

template <typename T>
struct constants {
  static constexpr T pi  = T(3.14159265358979323846264338327950288l);
  static constexpr T e   = T(2.71828182845904523536028747135266249l);
  static constexpr T tau = T(6.28318530717958647692528676655900576l);
};
