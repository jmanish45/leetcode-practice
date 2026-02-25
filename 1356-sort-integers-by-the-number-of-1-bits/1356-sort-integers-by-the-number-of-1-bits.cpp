class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,multiset<int>> mp;
        for(int i=0; i<arr.size(); i++) {
            int bits = __builtin_popcount(arr[i]);
            mp[bits].insert(arr[i]);

        }
        vector<int> ans;
        for(auto p : mp) {
            for(int val : p.second) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};