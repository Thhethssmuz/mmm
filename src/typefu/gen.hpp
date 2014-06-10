#ifndef mmm_typefu_gen_hpp
#define mmm_typefu_gen_hpp

namespace typefu {

  template <size_t x, size_t y, size_t... xs>
  struct max {
    static constexpr size_t value = max<(x >= y ? x : y), xs...>::value;
  };

  template <size_t x, size_t y>
  struct max<x, y> {
    static constexpr size_t value = x >= y ? x : y;
  };


  template <bool b, bool... bs>
  struct all {
    static constexpr bool value = b and all<bs...>::value;
  };

  template <bool b, bool c>
  struct all<b, c> {
    static constexpr bool value = b and c;
  };
}

#endif