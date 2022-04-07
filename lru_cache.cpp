// https://leetcode.com/problems/lru-cache/submissions/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>


class LRUCache {
public:
  LRUCache(int capacity) : _capacity(capacity) {}

  int get(int key) {
    if (cache.find(key) == cache.end()) return -1;

    touch(key);

    return cache[key].first;
  }

  void put(int key, int value) {
    if (cache.find(key) == cache.end()) {
        if (cache.size() == _capacity) {
          cache.erase(used.back());
          used.pop_back();
        }

        used.push_front(key);
    } else {
      touch(key);
    }

    cache[key] = { value, used.begin() };
  }

  void print() {
    std::cout << "{ " << std::endl;
    for (auto & [k, v]: cache) {
      std::cout << "  [" << k << "]: " << v.first << std::endl;
    }
    std::cout << "}" << std:: endl;
  }
private:
  typedef std::list<int> LI;
  typedef std::list<int>::iterator LII;
  typedef std::pair<int, LII> PII;

  void touch(int key) {
    auto listItem = cache[key].second;

    used.erase(listItem);

    //fixed:
    used.push_front(key);
    cache[key].second = used.begin();
  }

  LI used;
  std::unordered_map<int, PII> cache;
  int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
  LRUCache lRUCache = LRUCache(2);
  lRUCache.put(1, 1); // cache is {1=1}
  lRUCache.put(2, 2); // cache is {1=1, 2=2}
  lRUCache.print();
  auto a = lRUCache.get(1);    // return 1
  std::cout << "a: " << a << std::endl;
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  lRUCache.print();
  auto t = lRUCache.get(2);    // returns -1 (not found)
  std::cout << "t: " << t << std::endl;

  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  lRUCache.print();
  lRUCache.get(1);    // return -1 (not found)
  lRUCache.get(3);    // return 3
  lRUCache.get(4);    // return 4
}
