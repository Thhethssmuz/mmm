#ifndef mmm_vec_func_reduct_hpp
#define mmm_vec_func_reduct_hpp

template <typename T, size_t n>
constexpr T sum(const tvec<T, n>& v);

template <typename T>
constexpr T sum(const tvec<T, 2>& v);

template <typename T, size_t n, typename A>
constexpr T sum(const vecType<T, n, A>& v);


template <typename T, size_t n>
constexpr T product(const tvec<T, n>& v);

template <typename T>
constexpr T product(const tvec<T, 2>& v);

template <typename T, size_t n, typename A>
constexpr T product(const vecType<T, n, A>& v);

#endif