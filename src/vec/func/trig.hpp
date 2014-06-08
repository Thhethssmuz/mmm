#ifndef mmm_vec_func_trig_hpp
#define mmm_vec_func_trig_hpp

// all trigonometric functions are only defined for floating point types and
// floating vector types.

constexpr float PI = 3.141592653589793f;
constexpr double dPI = 3.14159265358979323846264338327950;
constexpr long double lPI = 3.141592653589793238462643383279502884197169399375l;


// degrees to radians conversion
constexpr float radians(float degrees);
constexpr double radians(double degrees);
constexpr long double radians(long double degrees);

template <typename T, typename = typefu::for_integral<T>>
constexpr typefu::promotef<T> radians(T degrees);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> radians(const tvec<T, n>& degrees);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> radians(const vecType<T, n, A>& degrees);


// radians to degrees conversion
constexpr float degrees(float radians);
constexpr double degrees(double radians);
constexpr long double degrees(long double radians);

template <typename T, typename = typefu::for_integral<T>>
constexpr typefu::promotef<T> degrees(T radians);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> degrees(const tvec<T, n>& radians);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> degrees(const vecType<T, n, A>& radians);


// sine
template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> sin(const tvec<T, n>& angle);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> sin(const vecType<T, n, A>& angle);


// cosine
template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> cos(const tvec<T, n>& angle);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> cos(const vecType<T, n, A>& angle);


// tangent
template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> tan(const tvec<T, n>& angle);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> tan(const vecType<T, n, A>& angle);


// component wise arcsine function generic
template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> asin(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> asin(const vecType<T, n, A>& x);


// component wise arccosine function generic
template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> acos(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> acos(const vecType<T, n, A>& x);


// component wise arctangent function generic
template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> atan(const tvec<T, n>& y_over_x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> atan(const vecType<T, n, A>& y_over_x);


// 2-argument variation of the atan function (aka. atan2)
template <typename T, typename = typefu::for_floating<T>>
constexpr T atan(T y, T x);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promotef<T, U> atan(T y, U x);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> atan(T y, const tvec<T, n>& x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, n> atan(U y, const vecType<T, n, A>& x);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> atan(const tvec<T, n>& y, T x);

template <typename T, typename U, size_t n, typename A,
          typename = typefu::for_floating<T>,
          typename = typefu::for_arithmetic<U>>
constexpr tvec<T, n> atan(const vecType<T, n, A>& y, U x);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> atan(const tvec<T, n>& y, const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_floating<T>>
constexpr tvec<T, n> atan(const vecType<T, n, A>& y, const vecType<T, n, B>& x);

#endif