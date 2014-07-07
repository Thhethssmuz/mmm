# mmm
In most cases mmm aims to mimic the OpenGL Shading Language (GLSL) as closely as possible, however, there are some notable differences. These documents aim to detail these differences as well as to serve as an abstract documentation of the code.

# Types
mmm defines several common 2D, 3D and 4D vector and matrix types.

## Vector types

| Types     | Description                                           |
|:----------|:------------------------------------------------------|
| **vec2**  | 2 dimensional single precision floating-point vector. |
| **vec3**  | 3 dimensional single precision floating-point vector. |
| **vec4**  | 4 dimensional single precision floating-point vector. |
| **dvec2** | 2 dimensional double precision floating-point vector. |
| **dvec3** | 3 dimensional double precision floating-point vector. |
| **dvec4** | 4 dimensional double precision floating-point vector. |
| **ivec2** | 2 dimensional signed integer vector.                  |
| **ivec3** | 3 dimensional signed integer vector.                  |
| **ivec4** | 4 dimensional signed integer vector.                  |
| **uvec2** | 2 dimensional unsigned integer vector.                |
| **uvec3** | 3 dimensional unsigned integer vector.                |
| **uvec4** | 4 dimensional unsigned integer vector.                |
| **bvec2** | 2 dimensional boolean vector.                         |
| **bvec3** | 3 dimensional boolean vector.                         |
| **bvec4** | 4 dimensional boolean vector.                         |

In addition to these types, mmm also defines templated versions of these types to allow for higher dimensional vectors.

| Types          | Description                                           |
|:---------------|:------------------------------------------------------|
| **vec\<N\>**   | N dimensional single precision floating-point vector. |
| **dvec\<N\>**  | N dimensional double precision floating-point vector. |
| **ivec\<N\>**  | N dimensional signed integer vector.                  |
| **uvec\<N\>**  | N dimensional unsigned integer vector.                |
| **bvec\<N\>**  | N dimensional boolean vector.                         |

## Matrix types

| Types     | Description                                        |
|:----------|:---------------------------------------------------|
| **mat2**  | 2x2 single precision floating-point square matrix. |
| **mat3**  | 3x3 single precision floating-point square matrix. |
| **mat4**  | 4x4 single precision floating-point square matrix. |
| **dmat2** | 2x2 double precision floating-point square matrix. |
| **dmat3** | 3x3 double precision floating-point square matrix. |
| **dmat4** | 4x4 double precision floating-point square matrix. |

| Types       | Description |
|:------------|:------------|
| **matNxM**  | N by M single precision floating-point matrix, where N is the number of columns in the matrix and M is the number of rows. Both N and M may be either 2, 3 or 4. |
| **dmatNxM** | N by M double precision floating-point matrix, where N is the number of columns in the matrix and M is the number of rows. Both N and M may be either 2, 3 or 4. |

In addition to these types, mmm also defines templated versions of these types to allow for larger matrices.

| Types            | Description |
|:-----------------|:------------|
| **mat\<N, M\>**  | N by M single precision floating-point matrix, where N is the number of columns in the matrix and M is the number of rows. |
| **dmat\<N, M\>** | N by M double precision floating-point matrix, where N is the number of columns in the matrix and M is the number of rows. |

## Implicit conversions
Unlike GLSL, mmm does not define any implicit conversions for vector and matrix types. Conversion may still be performed, but only through explicit vector and matrix constructors. This to avoid unexpected and unnecessary type conversions when performing various vector and matrix operations.

Standard C/C++ type promotion rules convert all integral types to doubles in any floating-point context. This would mean that an integral scalar value used in a floating vector context, say for example when adding a scalar and a vector, would result in a vector of type double, even if the original vector was of type float.

Instead mmm defines vectors and matrices to hold the dominant type over any scalar, such that a scalar used in a vector or matrix context will always convert to the type of the vector or matrix before the operation is performed.

Furthermore, mmm restricts all vector and matrix operations and functions to only vectors and matrices of the same type.

# Vector
## Swizzling
All vector types include several swizzle members that can be used to access individual, a subset or all of the vector components or to construct new vectors. Individual components may be referred to using any of the letters 'xyzw', 'rgba' or 'stpq'. The letters in each of the groups represents the 1st, 2nd, 3rd and 4th component of a vector respectively and may be combined in anyway up to a maximum of 4 components. Each of the letter groups are synonyms of each other and may be used interchangeably, but may not be mixed.

The swizzle operators return swizzle types that behave similarly to vectors in both an L-value and R-value context. In most cases these swizzle objects will simply cast to a vector object, copying the relevant components from its parent vector, however, they may also be used in assignment to modify the original vector.

```c++
vec4 v;
vec2 u;

...

v.x  = 0;     // assigns the first component of the vector v.
v.xy = u;     // assigns the first two components of the vector v to be equal
              // to the vector u.
v = v.wzyx;   // reverses the vector v.
```

Note that swizzle operators may specify an individual component multiple times which may be useful when used to construct new vectors, however, doing this when doing assignment results in some rather unintuitive behavior.

```c++
vec3 v;

...

vec4 u = v.xyzz; // constructs a new vector where both the 3rd and 4th
                 // component is equal to the 3rd component of the vector v.

u.xxyy += 2;     // adds 2 to the 1st and 2nd component of the vector u, TWICE!
u.xy += 4;       // synonymous with the above expression.
```

For vectors of higher dimensions mmm also defines two template member functions useful for accessing individual components of such vectors.

```c++
vec<48> v;

...

v.swizzleElems<11, 28, 34>() += 2; // adds 2 to the 11th, 28th and 34th
                                   // component of the vector v.

v.swizzleRange<30, 40>() = 0;      // sets all the components in the vector v
                                   // from and including the 30th element to
                                   // and including the 40th element to be
                                   // equal to 0.
```

## Constructors
By default all vectors are instantiated with 0's if no arguments are provided. If a single scalar value are provided the vector is initialized with all its components equal to that value.

A vector may also be constructed from any set of scalars, vectors or matrices, as long as the set contains at least as many components as the size of the vector that is to be constructed. Any extraneous components are dropped.

Scalar and vector arguments are consumed left to right and in the case of matrices components are consumed in column major order, i.e. column by column and consumes each column from top to bottom.

Vectors may also be constructed from vectors of different types, as long as a conversion from the underlying type of the argument vector to the underlying type of the new vector exists. However, for this to be legal the constructor may only be passed a single argument vector which must contain an equal number of components to the vector that is to be constructed.

```c++
vec2 v;              // initializes the vector with 0's
vec2 u = vec2(1);    // initializes the vector with 1's
vec4 t = vec4(v, u); // initializes the first two components to be equal to
                     // the vector v, and the last two components to be equal
                     // to the vector u. t == vec4(0, 0, 1, 1).
```
