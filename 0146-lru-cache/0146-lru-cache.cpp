class LRUCache {
public:
    list<pair<int, int>> li;
    int n;
    unordered_map<int , list<pair<int , int> >:: iterator> mp;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        auto it = mp[key];
        int value = it->second;
        li.erase(it);
        li.push_front({key, value});
        mp[key] = li.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            li.erase(mp[key]);

        }
        else if(li.size()==n) {
            mp.erase(li.back().first);
            li.pop_back();
        }
        li.push_front({key, value});
        mp[key] = li.begin();

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */