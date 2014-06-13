#ifndef mmm_vec_vectype_hpp
#define mmm_vec_vectype_hpp

template <typename T, size_t N, typename Derived>
struct vecType {};

template <typename T, size_t N>
struct tvec;

template <typename T, size_t N, typename D>
constexpr tvec<T, N> vec_cast(const vecType<T, N, D>& v);

template <typename T, size_t N>
constexpr tvec<T, N> vec_cast(const vecType<T, N, tvec<T, N>>& v);

#endif