#include <bloom_filter.h>

namespace app {

  bloom_filter::bloom_filter()
  : bf::basic_bloom_filter(bf::make_hasher(BF_K), BF_M)
  {
  }

  bloom_filter::bloom_filter(bloom_filter&& o)
  : basic_bloom_filter(std::move(o))
  {
  }

  size_t bloom_filter::lookupDigest(const std::vector<bf::digest>& digests)
  {
    auto bits = storage();
    for (auto d : digests) {
      if (!bits[d % bits.size()]) return 0;
    }
    return 1;
  }

}
