#include <iostream>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> lruList;
    map<int, int> lruMap;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        list<int>::iterator iter = find(lruList.begin(), lruList.end(), key);

        if (iter != lruList.end()) {
            lruList.erase(iter);
            lruList.push_back(key);

            return lruMap[key];
        }

        return -1;
    }

    void put(int key, int value) {
        list<int>::iterator iter = find(lruList.begin(), lruList.end(), key);

        if (iter != lruList.end()) {
            lruList.erase(iter);
            lruList.push_back(key);
            lruMap[key] = value;
        } else {
            if (lruList.size() >= capacity) {
                lruMap.erase(lruList.front());
                lruList.erase(lruList.begin());
            }

            lruList.push_back(key);
            lruMap[key] = value;
        }
    }
};

int main() {
    LRUCache *cache;

    cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;
    cache->put(3, 3);
    cout << cache->get(2) << endl;
    cache->put(4, 4);
    cout << cache->get(1) << endl;
    cout << cache->get(3) << endl;
    cout << cache->get(4) << endl;
    delete cache;

    return 0;
}