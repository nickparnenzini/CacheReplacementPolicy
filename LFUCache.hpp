#include "ICache.hpp"

#include <utility>
#include <map>
#include <unordered_map>

class LFUCache : public ICache {
public:
    LFUCache(std::size_t capacity) : ICache(capacity) 
    {
    }

    int get(int key);

    void put(int key, int value);
    
private:
    std::multimap<int, std::pair<int,int>> frequency_storage;  // key: frequency; value: pair of (key,value)
    std::unordered_map<int, std::multimap<int,std::pair<int,int>>::iterator> hashmap;  // key - iterator
};