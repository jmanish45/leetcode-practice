class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp;

    RandomizedSet() {}

    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int idx = mp[val];
        int last = arr.back();

        swap(arr[idx], arr.back());
        arr.pop_back();

        mp[last] = idx;   // fix
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
