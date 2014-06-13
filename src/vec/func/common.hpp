#ifndef mmm_vec_func_common_hpp
#define mmm_vec_func_common_hpp

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> abs(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> abs(const vecType<T, N, A>& x);


template <typename T, typename = typefu::for_signed<T>>
constexpr T sign(T x);

template <typename T, size_t N, typename = typefu::for_signed<T>>
constexpr tvec<T, N> sign(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_signed<T>>
constexpr tvec<T, N> sign(const vecType<T, N, A>& x);


template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> floor(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> floor(const vecType<T, N, A>& x);


template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> ceil(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> ceil(const vecType<T, N, A>& x);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> fract(T x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> fract(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> fract(const vecType<T, N, A>& x);


template <typename T, typename = typefu::for_integral<T>,
          typename = typefu::for_arithmetic<T>>
constexpr T mod(T x, T y);

template <typename T, typename = typefu::for_floating<T>>
constexpr T mod(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> mod(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> mod(T x, const tvec<T, N>& y);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> mod(U x, const vecType<T, N, A>& y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> mod(const tvec<T, N>& x, T y);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> mod(const vecType<T, N, A>& x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> mod(const tvec<T, N>& x, const tvec<T, N>& y);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> mod(const vecType<T, N, A>& x, const vecType<T, N, B>& y);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T min(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> min(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> min(T x, const tvec<T, N>& y);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> min(U x, const vecType<T, N, A>& y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> min(const tvec<T, N>& x, T y);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> min(const vecType<T, N, A>& x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> min(const tvec<T, N>& x, const tvec<T, N>& y);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> min(const vecType<T, N, A>& x, const vecType<T, N, B>& y);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T max(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> max(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> max(T x, const tvec<T, N>& y);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> max(U x, const vecType<T, N, A>& y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> max(const tvec<T, N>& x, T y);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> max(const vecType<T, N, A>& x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> max(const tvec<T, N>& x, const tvec<T, N>& y);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> max(const vecType<T, N, A>& x, const vecType<T, N, B>& y);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T clamp(T x, T minVal, T maxVal);

template <typename T, typename U, typename V,
          typename = typefu::for_arithmetic<T, U, V>>
constexpr typefu::promote<T, U, V> clamp(T x, U minVal, V maxVal);


template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> clamp(const tvec<T, N>& x, T minVal, T maxVal);

template <typename T, typename U, typename V, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U, V>>
constexpr tvec<T, N> clamp(const vecType<T, N, A>& x, U minVal, V maxVal);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> clamp(const tvec<T, N>& x, const tvec<T, N>& minVal,
                           const tvec<T, N>& maxVal);

template <typename T, size_t N, typename A, typename B, typename C,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> clamp(const vecType<T, N, A>& x,
                           const vecType<T, N, B>& minVal,
                           const vecType<T, N, C>& maxVal);


template <typename T, typename = typefu::for_floating<T>>
constexpr T mix(T x, T y, T a);

template <typename T, typename U, typename V,
          typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T, U, V> mix(T x, U y, V a);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> mix(const tvec<T, N>& x, const tvec<T, N>& y, T a);

template <typename T, typename U, size_t N, typename A, typename B,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, N> mix(const vecType<T, N, A>& x, const vecType<T, N, B>& y,
                         U a);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> mix(const tvec<T, N>& x, const tvec<T, N>& y,
                         const tvec<T, N>& a);

template <typename T, size_t N, typename A, typename B, typename C,
          typename = typefu::for_floating<T>>
constexpr tvec<T, N> mix(const vecType<T, N, A>& x, const vecType<T, N, B>& y,
                         const vecType<T, N, C>& a);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T step(T edge, T x);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> step(T edge, U x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> step(T edge, const tvec<T, N>& x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> step(U edge, const vecType<T, N, A>& x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> step(const tvec<T, N>& edge, T x);

template <typename T, typename U, size_t N, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, N> step(const vecType<T, N, A>& edge, U x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> step(const tvec<T, N>& edge, const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, N> step(const vecType<T, N, A>& edge,
                          const vecType<T, N, B>& x);

// smoothstep

#endif