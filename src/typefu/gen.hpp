#ifndef mmm_typefu_gen_hpp
#define mmm_typefu_gen_hpp

namespace typefu {

  template <size_t X, size_t... Xs>
  struct max {
    static constexpr size_t value = max<X, max<Xs...>::value>::value;
  };

  template <size_t X, size_t Y>
  struct max<X, Y> {
    static constexpr size_t value = X >= Y ? X : Y;
  };

  template <size_t X>
  struct max<X> {
    static constexpr size_t value = X;
  };


  template <bool B, bool... Bs>
  struct all {
    static constexpr bool value = B and all<Bs...>::value;
  };

  template <bool B, bool C>
  struct all<B, C> {
    static constexpr bool value = B and C;
  };

  template <bool B>
  struct all<B> {
    static constexpr bool value = B;
  };
}

#endif