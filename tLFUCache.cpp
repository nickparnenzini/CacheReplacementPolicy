#include "LFUCache.hpp"
#include <gtest/gtest.h>

TEST(LFUCacheTest, testEvicts) {
    ICache *lfu_cache = new LFUCache(2);
    lfu_cache->put(1,1);
    lfu_cache->put(2,2);
    ASSERT_EQ(1, lfu_cache->get(1));

    lfu_cache->put(3,3);
    ASSERT_EQ(-1, lfu_cache->get(2));
    ASSERT_EQ(3, lfu_cache->get(3));

    lfu_cache->put(4,4);
    ASSERT_EQ(-1, lfu_cache->get(1));
    ASSERT_EQ(3, lfu_cache->get(3));
    ASSERT_EQ(4, lfu_cache->get(4));

    delete lfu_cache;
}

TEST(LFUCacheTest, TestVoidLFU) {
    ICache *lfu_cache = new LFUCache(0);
    lfu_cache->put(1,1);
    ASSERT_EQ(-1, lfu_cache->get(1));
    delete lfu_cache;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
