#pragma once

#include <cstdint>

class ICache {
public:
	ICache() = delete;

	ICache(std::size_t capacity) :
	       m_capacity(capacity)
  {
	}

  virtual int get(int key) = 0;
  
  virtual void put(int key, int value) = 0;

  std::size_t capacity() {
      return m_capacity;
  }

private:
    std::size_t m_capacity;	
};
