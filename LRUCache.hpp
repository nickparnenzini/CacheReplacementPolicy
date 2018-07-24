#include "ICache.hpp"

#include <utility>
#include <list>
#include <unordered_map>

class LRUCache : public ICache {
public:
    LRUCache(std::size_t capacity) : ICache(capacity) 
    {       
    }

    ~LRUCache()
    {
    }

    int get(int key) override;

    void put(int key,int value) override;
    
private:
    std::list<std::pair<int,int>> cache;   // key-value pair
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> hashmap;
};
