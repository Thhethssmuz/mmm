#pragma once

template <size_t N>
using vec  = tvec<float, N>;
using vec2 = vec<2>;
using vec3 = vec<3>;
using vec4 = vec<4>;

template <size_t N>
using dvec  = tvec<double, N>;
using dvec2 = dvec<2>;
using dvec3 = dvec<3>;
using dvec4 = dvec<4>;

template <size_t N>
using bvec  = tvec<bool, N>;
using bvec2 = bvec<2>;
using bvec3 = bvec<3>;
using bvec4 = bvec<4>;

template <size_t N>
using ivec  = tvec<int, N>;
using ivec2 = ivec<2>;
using ivec3 = ivec<3>;
using ivec4 = ivec<4>;

template <size_t N>
using uvec  = tvec<unsigned int, N>;
using uvec2 = uvec<2>;
using uvec3 = uvec<3>;
using uvec4 = uvec<4>;


template <size_t N, size_t M>
using mat    = tmat<float, N, M>;
using mat2   = mat<2, 2>;
using mat3   = mat<3, 3>;
using mat4   = mat<4, 4>;
using mat2x2 = mat<2, 2>;
using mat2x3 = mat<2, 3>;
using mat2x4 = mat<2, 4>;
using mat3x2 = mat<3, 2>;
using mat3x3 = mat<3, 3>;
using mat3x4 = mat<3, 4>;
using mat4x2 = mat<4, 2>;
using mat4x3 = mat<4, 3>;
using mat4x4 = mat<4, 4>;

template <size_t N, size_t M>
using dmat    = tmat<double, N, M>;
using dmat2   = dmat<2, 2>;
using dmat3   = dmat<3, 3>;
using dmat4   = dmat<4, 4>;
using dmat2x2 = dmat<2, 2>;
using dmat2x3 = dmat<2, 3>;
using dmat2x4 = dmat<2, 4>;
using dmat3x2 = dmat<3, 2>;
using dmat3x3 = dmat<3, 3>;
using dmat3x4 = dmat<3, 4>;
using dmat4x2 = dmat<4, 2>;
using dmat4x3 = dmat<4, 3>;
using dmat4x4 = dmat<4, 4>;
