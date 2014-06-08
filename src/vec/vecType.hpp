#ifndef mmm_vec_vectype_hpp
#define mmm_vec_vectype_hpp

template <typename T, size_t n, typename Derived>
struct vecType {};

template <typename T, size_t n>
struct tvec;

template <typename T, size_t n, typename D>
constexpr tvec<T, n> vec_cast(const vecType<T, n, D>& v);

template <typename T, size_t n>
constexpr tvec<T, n> vec_cast(const vecType<T, n, tvec<T, n>>& v);

#endif