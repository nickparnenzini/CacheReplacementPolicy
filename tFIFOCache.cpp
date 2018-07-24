#include "FIFOCache.hpp"
#include <gtest/gtest.h>

TEST(FIFOCacheTest, testEvicts) {
	ICache *fifo_cache = new FIFOCache(2);

    fifo_cache->put(1,1);
    fifo_cache->put(2,2);
    ASSERT_EQ(1,fifo_cache->get(1));

    fifo_cache->put(3,3);
    ASSERT_EQ(2, fifo_cache->get(2));

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}