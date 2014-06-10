#ifndef mmm_typefu_range_hpp
#define mmm_typefu_range_hpp

template <typename T, size_t n, size_t... elems>
struct swizzle;

namespace typefu {

  template <bool done, typename T, size_t n, size_t prev, size_t end,
            size_t... range>
  struct build_positive_swizzle_range {};

  template <typename T, size_t n, size_t prev, size_t end, size_t... range>
  struct build_positive_swizzle_range<false, T, n, prev, end, range...> {
    typedef typename build_positive_swizzle_range<
      prev + 2 == end, T, n, prev + 1, end, range..., prev>::type type;
  };

  template <typename T, size_t n, size_t prev, size_t end, size_t... range>
  struct build_positive_swizzle_range<true, T, n, prev, end, range...> {
    typedef swizzle<T, n, range..., prev, end> type;
  };


  template <bool done, typename T, size_t n, size_t prev, size_t end,
            size_t... range>
  struct build_negative_swizzle_range {};

  template <typename T, size_t n, size_t prev, size_t end, size_t... range>
  struct build_negative_swizzle_range<false, T, n, prev, end, range...> {
    typedef typename build_negative_swizzle_range<
      prev - 2 == end, T, n, prev - 1, end, range..., prev>::type type;
  };

  template <typename T, size_t n, size_t prev, size_t end, size_t... range>
  struct build_negative_swizzle_range<true, T, n, prev, end, range...> {
    typedef swizzle<T, n, range..., prev, end> type;
  };


  template <typename T, size_t n, size_t start, size_t end, bool = start <= end>
  struct dispatch_swizzle_range {
    static_assert(start != end, "invalid swizzle range");
    typedef typename build_positive_swizzle_range<start + 1 == end, T, n, start,
                                                  end>::type type;
  };

  template <typename T, size_t n, size_t start, size_t end>
  struct dispatch_swizzle_range<T, n, start, end, false> {
    typedef typename build_negative_swizzle_range<start - 1 == end, T, n, start,
                                                  end>::type type;
  };


  template <typename T, size_t n, size_t start, size_t end>
  using swizzle_range = typename dispatch_swizzle_range<T, n, start, end>::type;
}

#endif