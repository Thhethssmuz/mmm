#ifndef mmm_hpp
#define mmm_hpp

#include <cstddef>
#include <cstdlib>
#include <type_traits>
#include <utility>
#include <cmath>
#include <iostream>

/*
  TODO:
    be consistent about using upper case for template vars
      change all mentions of size_t n to size_t N
      also Elems, and L,
  --------------------------------------------------------

  typefu/
    traits
    restrict
    promote
    components
    gen

  mat/

  swizzle/
    swizzle
    swizzle1

    opr/
      asig
      enum

  vec/           mostly complete
    vecType      no explicit tests
    tvec         complete!
    tvec2        no explicit tests

    opr/         complete!
      asig       complete!
      enum       complete!
      num        complete!
      comp       complete!
      io         complete!

    func/        lacking some functions
      trig       failed test 'atan2'!
      exp        complete!
      common     2 missing: smoothstep
      geo        3 missing: faceforward, reflect, refract
      rel        complete!
      reduct     complete!
      io         complete!
*/

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


template <size_t n> using  vec = tvec<float,n>;
template <size_t n> using dvec = tvec<double,n>;
template <size_t n> using bvec = tvec<bool,n>;
template <size_t n> using ivec = tvec<int,n>;
template <size_t n> using uvec = tvec<unsigned int,n>;

typedef vec<2> vec2;
typedef vec<3> vec3;
typedef vec<4> vec4;

typedef dvec<2> dvec2;
typedef dvec<3> dvec3;
typedef dvec<4> dvec4;

typedef bvec<2> bvec2;
typedef bvec<3> bvec3;
typedef bvec<4> bvec4;

typedef ivec<2> ivec2;
typedef ivec<3> ivec3;
typedef ivec<4> ivec4;

typedef uvec<2> uvec2;
typedef uvec<3> uvec3;
typedef uvec<4> uvec4;

#endif