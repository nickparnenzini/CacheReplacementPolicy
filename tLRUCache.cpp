#include "LRUCache.hpp"
#include <gtest/gtest.h>

TEST(LRUCacheTest, testEvicts) {
    ICache *lru_cache = new LRUCache(2);

    lru_cache->put(1,1);
    lru_cache->put(2,2);
    ASSERT_EQ(1,lru_cache->get(1));

    lru_cache->put(3,3);
    ASSERT_EQ(-1, lru_cache->get(2));
    ASSERT_EQ(3, lru_cache->get(3));

    lru_cache->put(4,4);
    ASSERT_EQ(-1, lru_cache->get(1));
    ASSERT_EQ(3, lru_cache->get(3));

    delete lru_cache;	
}

TEST(LRUCacheTest, testVoidLRU) {

	ICache *lru_cache = new LRUCache(0);
	lru_cache->put(1,1);
	ASSERT_EQ(-1, lru_cache->get(1));
	delete lru_cache;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}