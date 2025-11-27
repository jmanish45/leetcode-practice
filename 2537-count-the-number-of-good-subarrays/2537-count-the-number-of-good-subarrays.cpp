class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        unordered_map<int, long long> mp;
        long long paircount = 0;
        int l = 0;
        int r = 0;
        while (r < n) {
            paircount+=mp[nums[r]];
            mp[nums[r]]++;
            
            while(paircount>=k) {
                count+=(n-r);

                mp[nums[l]]--;
                paircount -= mp[nums[l]];
                l++;
            }
            

            r++;
        }
        return count;
    }
};