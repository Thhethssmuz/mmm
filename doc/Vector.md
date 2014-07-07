# mmm vectors

<!--
## Member functions
```c++
swizzle& swizzleElems<Elems...>();

swizzle& swizzleRange<Start, End>();
```

## Operators
```c++
scalar&  operator[] (size_t i);

vec&     operator=  (const vec& v);

...
```
-->

## Functions
### GLSL trigonometric functions
All trigonometric functions are defined for all floating scalars and floating vector types.

#### Radians
```c++
scalar   radians (scalar degrees);
vec      radians (vec degrees);
```
Convert degrees to radians. For vector arguments the operation is performed for each component in the vector.

#### Degrees
```c++
scalar   degrees (scalar radians);
vec      degrees (vec radians);
```
Convert radians to degrees. For vector arguments the operation is performed for each component in the vector.

#### Sine
```c++
scalar   sin (scalar angle);
vec      sin (vec angle);
```
Calculate the sine of the angle, the angle is assumed to be in radians. For vector arguments the operation is performed for each component in the vector.

#### Cosine
```c++
scalar   cos (scalar angle);
vec      cos (vec angle);
```
Calculate the cosine of the angle in radians. For vector arguments the operation is performed for each component in the vector.

#### Tangent
```c++
scalar   tan (scalar angle);
vec      tan (vec angle);
```
Calculate the tangent of the angle in radians. For vector arguments the operation is performed for each component in the vector.

#### Arc sine
```c++
scalar   asin (scalar x);
vec      asin (vec x);
```
Calculate the arcsine of an angle in radians. For vector arguments the operation is performed for each component in the vector.

#### Arc cosine
```c++
scalar   acos (scalar x);
vec      acos (vec x);
```
Calculate the arccosine of an angle in radians. For vector arguments the operation is performed for each component in the vector.

#### Arc tangent
```c++
scalar   atan (scalar y_over_x);
vec      atan (vec y_over_x);
```
Calculate the arctangent of an angle in radians. For vector arguments the operation is performed for each component in the vector.

```c++
scalar   atan (scalar y, scalar x);
vec      atan (scalar y, vec x);
vec      atan (vec y, scalar x);
vec      atan (vec y, vec x);
```
Two argument variant of the atan function, aka. atan2. For scalar and vector arguments the operation is performed for each component in the vector, for 2 vector arguments the operation is performed component wise.

### GLSL exponential functions
All exponential functions are defined for all floating scalars and floating vector types.

#### Exponentiation
```c++
scalar   pow (scalar x, scalar y);
vec      pow (vec x, vec y);
```
Returns x raised to the power of y. For vector arguments the operation is performed for each component in the vector.

#### Exponential function
```c++
scalar   exp (scalar x);
vec      exp (vec x);
```
Returns the constant e raised to the power of x. For vector arguments the operation is performed for each component in the vector.

#### Natural logarithm
```c++
scalar   log (scalar x);
vec      log (vec x);
```
Returns the power to which the constant e has to be raised to produce x. For vector arguments the operation is performed for each component in the vector.

#### Exponential function (base 2)
```c++
scalar   exp2 (scalar x);
vec      exp2 (vec x);
```
Returns 2 raised to the power of x. For vector arguments the operation is performed for each component in the vector.

#### Logarithm (base 2)
```c++
scalar   log2 (scalar x);
vec      log2 (vec x);
```
Returns the power to which 2 has to be raised to produce x. For vector arguments the operation is performed for each component in the vector.

#### Square root
```c++
scalar   sqrt (scalar x);
vec      sqrt (vec x);
```
Returns the square root of x. For vector arguments the operation is performed for each component in the vector.

#### Inverse square root
```c++
vec      inversesqrt (scalar x);
vec      inversesqrt (vec x);
```
Returns the reciprocal of the square root of x, i.e. 1 over the square root of x. For vector arguments the operation is performed for each component in the vector.

### GLSL Common Functions
#### Absolute value
```c++
scalar   abs (scalar x);
vec      abs (vec x);
```
Returns the absolute value of x. For vector arguments the operation is performed for each component in the vector. Defined for all floating scalars and floating vector types.

#### Sign
```c++
scalar   sign (scalar x);
vec      sign (vec x);
```
Returns 1 if x is positive, 0 if x is equal to 0 and -1 otherwise. For vector arguments the operation is performed for each component in the vector. Defined for all signed integral and floating scalars as well as all signed integral and floating vector types.

#### Floor
```c++
scalar   floor (scalar x);
vec      floor (vec x);
```
Returns the largest integral value that is not greater than x, expressed as a floating point value. For vector arguments the operation is performed for each component in the vector. Defined for all floating scalars and floating vector types.

#### Ceiling
```c++
scalar   ceil (scalar x);
vec      ceil (vec x);
```
Returns the smallest integral value that is not less than x, expressed as a floating point value. For vector arguments the operation is performed for each component in the vector. Defined for all floating scalars and floating vector types.

#### Fractional part
```c++
scalar   fract (scalar x);
vec      fract (vec x);
```
Returns the fractional part of x. For vector arguments the operation is performed for each component in the vector. Defined for all floating scalars and floating vector types.

#### Modulus
```c++
scalar   mod (scalar x, scalar y);
vec      mod (scalar x, vec y);
vec      mod (vec x, scalar y);
vec      mod (vec x, vec y);
```
Returns the modulo of x and y. For scalar and vector arguments the operation is performed for each component in the vector, for 2 vector arguments the operation is performed component wise. Defined for all arithmetic scalars and arithmetic vector types.

#### Minimum
```c++
scalar   min (scalar x, scalar y);
vec      min (scalar x, vec y);
vec      min (vec x, scalar y);
vec      min (vec x, vec y);
```
Returns the smallest of the two arguments. For scalar and vector arguments the operation is performed for each component in the vector, for 2 vector arguments the operation is performed component wise. Defined for all arithmetic scalars and arithmetic vector types.

#### Maximum
```c++
scalar   max (scalar x, scalar y);
vec      max (scalar x, vec y); 
vec      max (vec x, scalar y); 
vec      max (vec x, vec y); 
```
Returns the greatest of the two arguments. For scalar and vector arguments the operation is performed for each component in the vector, for 2 vector arguments the operation is performed component wise. Defined for all arithmetic scalars and arithmetic vector types.

#### Clamp
```c++
scalar   clamp (scalar x, scalar minVal, scalar maxVal);
vec      clamp (vec x, scalar minVal, scalar maxVal);
vec      clamp (vec x, vec minVal, vec maxVal);
```
Returns x if x is in the range from minVal to maxVal, otherwise it returns minVal if x is less then minVal or maxVal if x is greater than maxVal. For vector arguments the operation is performed component wise. Defined for all arithmetic scalars and arithmetic vector types.

#### Mix
```c++
scalar   mix (scalar x, scalar y, scalar a);
vec      mix (vec x, vec y, scalar a);
vec      mix (vec x, vec y, vec a);
```
Returns the linear blend of x and y at a ratio equal to a. For vector arguments the operation is performed component wise. Defined for all floating scalars and floating vector types.

#### Step
```c++
scalar   step (scalar edge, scalar x);
vec      step (scalar edge, vec x);
vec      step (vec edge, scalar x);
vec      step (vec edge, vec x);
```
Returns 0 if x is smaller than edge otherwise it returns 1. For vector arguments the operation is performed component wise. Defined for all arithmetic scalars and arithmetic vector types.

### GLSL Geometric Functions
#### Length
```c++
scalar   length (scalar x);
scalar   length (vec x);
```
Returns the length of the vector x. For scalar arguments the returned value is simply the absolute value. Defined for all arithmetic scalars and arithmetic vector types. The returned scalar is always a floating value.

#### Distance
```c++
scalar   distance (scalar p0, scalar p1);
scalar   distance (vec p0, vec p1);
```
Returns the distance between p0 and p1. Defined for all arithmetic scalars and arithmetic vector types. The returned scalar is always a floating value.

#### Dot product
```c++
scalar   dot (scalar x, scalar y);
scalar   dot (vec x, vec y);
```
Returns the dot product of x and y. Defined for all arithmetic scalars and arithmetic vector types.

#### Cross product
```c++
vec3     cross (vec3 x, vec3 y);
```
Returns the cross product of x and y. Defined for all signed 3-component vector types.

#### Normalize
```c++
scalar   normalize (scalar x);
vec      normalize (vec x);
```
Returns a vector in the same direction as x with a length of 1. For scalars the result is simply 1. Defined for all floating scalar and floating vector types.

### GLSL Relational Functions
All relational functions are defined for all arithmetic scalar and arithmetic vector types.

#### Less than
```c++
bool     lessThan (scalar x, scalar y);
bvec     lessThan (scalar x, vec y);
bvec     lessThan (vec x, scalar y);
bvec     lessThan (vec x, vec y);
```
Returns a component wise evaluation of x < y.

#### Less than or equal
```c++
bool     lessThanEqual (scalar x, scalar y);
bvec     lessThanEqual (scalar x, vec y);
bvec     lessThanEqual (vec x, scalar y);
bvec     lessThanEqual (vec x, vec y);
```
Returns a component wise evaluation of x <= y.

#### Greater than
```c++
bool     greaterThan (scalar x, scalar y);
bvec     greaterThan (scalar x, vec y);
bvec     greaterThan (vec x, scalar y);
bvec     greaterThan (vec x, vec y);
```
Returns a component wise evaluation of x > y.

#### Greater than or equal
```c++
bool     greaterThanEqual (scalar x, scalar y);
bvec     greaterThanEqual (scalar x, vec y);
bvec     greaterThanEqual (vec x, scalar y);
bvec     greaterThanEqual (vec x, vec y);
```
Returns a component wise evaluation of x >= y.

#### Equal
```c++
bool     equal (scalar x, scalar y);
bvec     equal (scalar x, vec y);
bvec     equal (vec x, scalar y);
bvec     equal (vec x, vec y);
```
Returns a component wise evaluation of x == y.

#### Not equal
```c++
bool     notEqual (scalar x, scalar y);
bvec     notEqual (scalar x, vec y);
bvec     notEqual (vec x, scalar y);
bvec     notEqual (vec x, vec y);
```
Returns a component wise evaluation of x != y.

#### Any
```c++
bool     any (bool x);
bool     any (bvec x);
```
Returns true if any of the components in x are true and false otherwise.

#### All
```c++
bool     all (bool x);
bool     all (bvec x);
```
Returns true if all of the components in x are true and false otherwise.

#### Not
```c++
bool     not (bool x);
bvec     not (bvec x);
```
Returns the negated boolean vector x. Implemented using the 'not' or '!' operator so parentheses are not strictly necessary.

### Reduction Functions
#### Sum
```c++
scalar   sum (vec v);
```
Calculates the sum of all the vector components. Defined for all arithmetic vector types.

#### Product
```c++
scalar   product (vec v);
```
Calculates the product of all the vector components. Defined for all arithmetic vector types.

#### Take
```c++
var      take<N>(vec v);
```
Returns the first N components of the vector, if only 1 component is taken the return type is a scaler, otherwise it is a vector.

#### Drop
```c++
var      drop<N>(vec v);
```
Returns a vector where the first N components of the vector have been dropped. If the resulting vector only have a single component left the return type is a scalar, otherwise it is a vector.

### IO Functions
#### Print
```c++
void     print (vec v);
```
Prints the vector to stdout.
