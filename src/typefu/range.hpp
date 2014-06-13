#ifndef mmm_typefu_range_hpp
#define mmm_typefu_range_hpp

template <typename T, size_t N, size_t... Elems>
struct swizzle;

namespace typefu {

  template <bool Done, typename T, size_t N, size_t Prev, size_t End,
            size_t... Range>
  struct build_positive_swizzle_range {};

  template <typename T, size_t N, size_t Prev, size_t End, size_t... Range>
  struct build_positive_swizzle_range<false, T, N, Prev, End, Range...> {
    typedef typename build_positive_swizzle_range<
      Prev + 2 == End, T, N, Prev + 1, End, Range..., Prev>::type type;
  };

  template <typename T, size_t N, size_t Prev, size_t End, size_t... Range>
  struct build_positive_swizzle_range<true, T, N, Prev, End, Range...> {
    typedef swizzle<T, N, Range..., Prev, End> type;
  };


  template <bool Done, typename T, size_t N, size_t Prev, size_t End,
            size_t... Range>
  struct build_negative_swizzle_range {};

  template <typename T, size_t N, size_t Prev, size_t End, size_t... Range>
  struct build_negative_swizzle_range<false, T, N, Prev, End, Range...> {
    typedef typename build_negative_swizzle_range<
      Prev - 2 == End, T, N, Prev - 1, End, Range..., Prev>::type type;
  };

  template <typename T, size_t N, size_t Prev, size_t End, size_t... Range>
  struct build_negative_swizzle_range<true, T, N, Prev, End, Range...> {
    typedef swizzle<T, N, Range..., Prev, End> type;
  };


  template <typename T, size_t N, size_t start, size_t End, bool = start <= End>
  struct dispatch_swizzle_range {
    static_assert(start != End, "invalid swizzle range");
    typedef typename build_positive_swizzle_range<start + 1 == End, T, N, start,
                                                  End>::type type;
  };

  template <typename T, size_t N, size_t start, size_t End>
  struct dispatch_swizzle_range<T, N, start, End, false> {
    typedef typename build_negative_swizzle_range<start - 1 == End, T, N, start,
                                                  End>::type type;
  };


  template <typename T, size_t N, size_t start, size_t End>
  using swizzle_range = typename dispatch_swizzle_range<T, N, start, End>::type;
}

#endif