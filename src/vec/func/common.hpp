#ifndef mmm_vec_func_common_hpp
#define mmm_vec_func_common_hpp

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> abs(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> abs(const vecType<T, n, A>& x);


template <typename T, typename = typefu::for_signed<T>>
constexpr T sign(T x);

template <typename T, size_t n, typename = typefu::for_signed<T>>
constexpr tvec<T, n> sign(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_signed<T>>
constexpr tvec<T, n> sign(const vecType<T, n, A>& x);


template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> floor(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> floor(const vecType<T, n, A>& x);


template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> ceil(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> ceil(const vecType<T, n, A>& x);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> fract(T x);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> fract(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> fract(const vecType<T, n, A>& x);


template <typename T, typename = typefu::for_integral<T>,
          typename = typefu::for_arithmetic<T>>
constexpr T mod(T x, T y);

template <typename T, typename = typefu::for_floating<T>>
constexpr T mod(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> mod(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> mod(T x, const tvec<T, n>& y);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> mod(U x, const vecType<T, n, A>& y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> mod(const tvec<T, n>& x, T y);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> mod(const vecType<T, n, A>& x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> mod(const tvec<T, n>& x, const tvec<T, n>& y);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> mod(const vecType<T, n, A>& x, const vecType<T, n, B>& y);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T min(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> min(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> min(T x, const tvec<T, n>& y);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> min(U x, const vecType<T, n, A>& y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> min(const tvec<T, n>& x, T y);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> min(const vecType<T, n, A>& x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> min(const tvec<T, n>& x, const tvec<T, n>& y);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> min(const vecType<T, n, A>& x, const vecType<T, n, B>& y);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T max(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> max(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> max(T x, const tvec<T, n>& y);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> max(U x, const vecType<T, n, A>& y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> max(const tvec<T, n>& x, T y);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> max(const vecType<T, n, A>& x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> max(const tvec<T, n>& x, const tvec<T, n>& y);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> max(const vecType<T, n, A>& x, const vecType<T, n, B>& y);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T clamp(T x, T minVal, T maxVal);

template <typename T, typename U, typename V,
          typename = typefu::for_arithmetic<T, U, V>>
constexpr typefu::promote<T, U, V> clamp(T x, U minVal, V maxVal);


template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> clamp(const tvec<T, n>& x, T minVal, T maxVal);

template <typename T, typename U, typename V, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U, V>>
constexpr tvec<T, n> clamp(const vecType<T, n, A>& x, U minVal, V maxVal);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> clamp(const tvec<T, n>& x, const tvec<T, n>& minVal,
                           const tvec<T, n>& maxVal);

template <typename T, size_t n, typename A, typename B, typename C,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> clamp(const vecType<T, n, A>& x,
                           const vecType<T, n, B>& minVal,
                           const vecType<T, n, C>& maxVal);


template <typename T, typename = typefu::for_floating<T>>
constexpr T mix(T x, T y, T a);

template <typename T, typename U, typename V,
          typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T, U, V> mix(T x, U y, V a);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> mix(const tvec<T, n>& x, const tvec<T, n>& y, T a);

template <typename T, typename U, size_t n, typename A, typename B,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, n> mix(const vecType<T, n, A>& x, const vecType<T, n, B>& y,
                         U a);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> mix(const tvec<T, n>& x, const tvec<T, n>& y,
                         const tvec<T, n>& a);

template <typename T, size_t n, typename A, typename B, typename C,
          typename = typefu::for_floating<T>>
constexpr tvec<T, n> mix(const vecType<T, n, A>& x, const vecType<T, n, B>& y,
                         const vecType<T, n, C>& a);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T step(T edge, T x);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> step(T edge, U x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> step(T edge, const tvec<T, n>& x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> step(U edge, const vecType<T, n, A>& x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> step(const tvec<T, n>& edge, T x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_arithmetic<T, U>>
constexpr tvec<T, n> step(const vecType<T, n, A>& edge, U x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> step(const tvec<T, n>& edge, const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, n> step(const vecType<T, n, A>& edge,
                          const vecType<T, n, B>& x);

// smoothstep

#endif