#pragma once

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator++(tvec<T, N>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N> operator++(tvec<T, N>& v, int);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N>& operator--(tvec<T, N>& v);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
tvec<T, N> operator--(tvec<T, N>& v, int);
