#ifndef mmm_typefu_gen_hpp
#define mmm_typefu_gen_hpp

namespace typefu {

  template <size_t x, size_t y, size_t... xs>
  struct max {
    static const size_t value = max<(x >= y ? x : y), xs...>::value;
  };

  template <size_t x, size_t y>
  struct max<x, y> {
    static const size_t value = x >= y ? x : y;
  };
}

#endif