#ifndef mmm_vec_func_geo_hpp
#define mmm_vec_func_geo_hpp

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> length(T x);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> length(const tvec<T, n>& v);

template <typename T, size_t n, typename A,
          typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> length(const vecType<T, n, A>& v);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T distance(T p0, T p1);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> distance(T p0, U p1);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> distance(const tvec<T, n>& p0,
                                       const tvec<T, n>& p1);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> distance(const vecType<T, n, A>& p0,
                                       const vecType<T, n, B>& p1);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T dot(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> dot(T x, U y);

template <typename T, size_t n, typename = typefu::for_arithmetic<T>>
constexpr T dot(const tvec<T, n>& v, const tvec<T, n>& u);

template <typename T, size_t n, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr T dot(const vecType<T, n, A>& v, const vecType<T, n, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr tvec<T, 3> cross(const tvec<T, 3>& v, const tvec<T, 3>& u);
template <typename T, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr tvec<T, 3> cross(const vecType<T, 3, A>& v,
                           const vecType<T, 3, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T normalize(T x);

template <typename T, size_t n, typename = typefu::for_floating<T>>
constexpr tvec<T, n> normalize(const tvec<T, n>& x);

template <typename T, size_t n, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, n> normalize(const vecType<T, n, A>& x);

// faceforward

// reflect

// refract

#endif