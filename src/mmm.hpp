#ifndef mmm_hpp
#define mmm_hpp

#include <cstddef>
#include <cstdlib>
#include <type_traits>
#include <utility>
#include <cmath>
#include <iostream>


#include <typefu/traits.hpp>
#include <typefu/restrict.hpp>
#include <typefu/promote.hpp>
#include <typefu/components.hpp>
#include <typefu/gen.hpp>


#include <vec/vecType.hpp>
#include <swizzle/swizzle.hpp>
#include <swizzle/swizzle1.hpp>
#include <vec/tvec.hpp>
#include <vec/tvec2.hpp>

#include <vec/opr/asig.hpp>
#include <vec/opr/enum.hpp>
#include <vec/opr/num.hpp>
#include <vec/opr/comp.hpp>
#include <vec/opr/io.hpp>

#include <vec/func/trig.hpp>
#include <vec/func/exp.hpp>
#include <vec/func/common.hpp>
#include <vec/func/geo.hpp>
#include <vec/func/rel.hpp>
#include <vec/func/reduct.hpp>
#include <vec/func/io.hpp>


#include <vec/vecType.tpp>
#include <swizzle/swizzle.tpp>
#include <swizzle/swizzle1.tpp>
#include <vec/tvec.tpp>
#include <vec/tvec2.tpp>

#include <vec/opr/asig.tpp>
#include <vec/opr/enum.tpp>
#include <vec/opr/num.tpp>
#include <vec/opr/comp.tpp>
#include <vec/opr/io.tpp>

#include <vec/func/trig.tpp>
#include <vec/func/exp.tpp>
#include <vec/func/common.tpp>
#include <vec/func/geo.tpp>
#include <vec/func/rel.tpp>
#include <vec/func/reduct.tpp>
#include <vec/func/io.tpp>


template <size_t n>
using vec  = tvec<float,n>;
using vec2 = vec<2>;
using vec3 = vec<3>;
using vec4 = vec<4>;

template <size_t n>
using dvec  = tvec<double,n>;
using dvec2 = dvec<2>;
using dvec3 = dvec<3>;
using dvec4 = dvec<4>;

template <size_t n>
using bvec  = tvec<bool,n>;
using bvec2 = bvec<2>;
using bvec3 = bvec<3>;
using bvec4 = bvec<4>;

template <size_t n>
using ivec  = tvec<int,n>;
using ivec2 = ivec<2>;
using ivec3 = ivec<3>;
using ivec4 = ivec<4>;

template <size_t n>
using uvec  = tvec<unsigned int,n>;
using uvec2 = uvec<2>;
using uvec3 = uvec<3>;
using uvec4 = uvec<4>;

#endif