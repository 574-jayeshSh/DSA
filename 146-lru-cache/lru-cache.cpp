class LRUCache {
private:
    int cap;
    list<pair<int, int>> dll; // Doubly Linked List: {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        
        // Move accessed node to the front
        auto node = mp[key];
        int val = node->second;
        dll.erase(node);
        dll.push_front({key, val});
        mp[key] = dll.begin();
        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Remove existing node
            dll.erase(mp[key]);
        }
        else if (dll.size() == cap) {
            // Remove LRU item (from back)
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }
        // Insert new item at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
