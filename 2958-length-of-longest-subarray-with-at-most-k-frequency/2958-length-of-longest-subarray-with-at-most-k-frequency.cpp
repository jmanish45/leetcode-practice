class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int, int> mp;
        int len = 0;
        int maxlen = 0;
        while(r<n) {
            while(mp.find(nums[r])!=mp.end() && mp[nums[r]]==k) {
                
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            mp[nums[r]]++;
            len = r-l+1;
            maxlen = max(maxlen,  len);
            r++;
        }
        return maxlen;
    }
};