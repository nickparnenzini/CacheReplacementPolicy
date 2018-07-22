#include "LFUCache.hpp"

int LFUCache::get(int key) { 
    auto it = hashmap.find(key);
    if (it == hashmap.end()) {
        return -1;
    }
    auto itMultimap = it->second;
    std::pair<int,int> p = itMultimap->second;   
    auto updated_elem = std::make_pair(itMultimap->first + 1, p);
    frequency_storage.erase(itMultimap);
    it->second = frequency_storage.emplace(std::move(updated_elem));        
    return p.second;
}
    
void LFUCache::put(int key, int value) { 
    if (this->capacity() > 0) {
        auto it = hashmap.find(key);    
        if (it == hashmap.end()) {     
            if (frequency_storage.size() == this->capacity()) {  // delete first element   
                auto it_cache = frequency_storage.begin();    
                std::pair<int,int> old_pair = it_cache->second;  
                frequency_storage.erase(it_cache);
                auto it_map = hashmap.find(old_pair.first);
                hashmap.erase(it_map);
            }
            std::pair<int,int> p = std::make_pair(key,value);
            auto new_it = frequency_storage.insert(std::make_pair(1,p));
            hashmap.insert(make_pair(key, new_it));
        }
        else {
            auto it_cache = it->second;
            std::pair<int,int> p  = std::make_pair(key,value);
            auto updated_elem = std::make_pair(it_cache->first+1, p);
            frequency_storage.erase(it_cache);
            it->second = frequency_storage.emplace(std::move(updated_elem));   
        }
    }
}