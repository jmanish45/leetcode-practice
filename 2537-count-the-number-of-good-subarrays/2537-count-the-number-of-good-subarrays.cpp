class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0; //subarray count
        int pairs = 0;
        unordered_map<int, long long> mp;
        int l = 0;
        int r = 0;
        while(r<n) {
            pairs+=mp[nums[r]];
            mp[nums[r]]++;
            while(pairs>=k) {
                count+=(n-r);
                mp[nums[l]]--;
                pairs-=mp[nums[l]];
                l++;
            }
            r++;
        }
        return count;
    }
};