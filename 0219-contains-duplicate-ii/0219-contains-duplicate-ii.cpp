class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++) {
            int p = nums[i];
            if(mp.find(p)!=mp.end()){
                int diff = i - mp[p];
                if(diff<=k) return true;
            }
            mp[p] = i;
        }
        return false;
    }
};