#include "LRUCache.hpp"

int LRUCache::get(int key) { 
    auto it = hashmap.find(key);  
    if (it == hashmap.end()) {  
        return -1;
    }
    auto itList = it->second;
    int value = itList->second;  
    cache.erase(it->second);   
    std::pair<int,int> p = std::make_pair(key,value);
    cache.push_front(p);
    itList = cache.begin();
    it->second = itList;
    return value;
}
    
void LRUCache::put(int key, int value) {  
    if (this->capacity() > 0) {
        auto it = hashmap.find(key);
        if (it == hashmap.end()) {   
            std::pair<int,int> p = std::make_pair(key,value);
            cache.push_front(p);
            auto itList = cache.begin();
            hashmap.insert(make_pair(key,itList));                      
            if (cache.size() > this->capacity()) {   
                std::pair<int,int> old_pair = cache.back();
                auto itMap = hashmap.find(old_pair.first);
                hashmap.erase(itMap);
                cache.pop_back();                  
            }
        }
        else {
            auto itList = it->second;
            cache.erase(itList);
            std::pair<int,int> p  = std::make_pair(key,value);
            cache.push_front(p);
            itList = cache.begin();
            it->second = itList;
        }
    }
}