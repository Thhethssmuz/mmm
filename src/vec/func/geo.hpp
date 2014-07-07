#ifndef mmm_vec_func_geo_hpp
#define mmm_vec_func_geo_hpp

template <typename T, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> length(T x);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> length(const tvec<T, N>& v);

template <typename T, size_t N, typename A,
          typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> length(const vecType<T, N, A>& v);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T distance(T p0, T p1);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> distance(T p0, U p1);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> distance(const tvec<T, N>& p0,
                                       const tvec<T, N>& p1);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr typefu::promotef<T> distance(const vecType<T, N, A>& p0,
                                       const vecType<T, N, B>& p1);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T dot(T x, T y);

template <typename T, typename U, typename = typefu::for_arithmetic<T, U>>
constexpr typefu::promote<T, U> dot(T x, U y);

template <typename T, size_t N, typename = typefu::for_arithmetic<T>>
constexpr T dot(const tvec<T, N>& v, const tvec<T, N>& u);

template <typename T, size_t N, typename A, typename B,
          typename = typefu::for_arithmetic<T>>
constexpr T dot(const vecType<T, N, A>& v, const vecType<T, N, B>& u);


template <typename T, typename = typefu::for_signed<T>>
constexpr tvec<T, 3> cross(const tvec<T, 3>& v, const tvec<T, 3>& u);

template <typename T, typename A, typename B,
          typename = typefu::for_signed<T>>
constexpr tvec<T, 3> cross(const vecType<T, 3, A>& v,
                           const vecType<T, 3, B>& u);


template <typename T, typename = typefu::for_arithmetic<T>>
constexpr T normalize(T x);

template <typename T, size_t N, typename = typefu::for_floating<T>>
constexpr tvec<T, N> normalize(const tvec<T, N>& x);

template <typename T, size_t N, typename A, typename = typefu::for_floating<T>>
constexpr tvec<T, N> normalize(const vecType<T, N, A>& x);

// faceforward

// reflect

// refract

#endif