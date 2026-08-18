class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        int maxi = -1;
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                if (mp[nums[i]] == 1) {
                    maxi = max(maxi, nums[i]);
                }
            }
        }
        else if (k == n) {
            for(auto x : nums) {
                maxi = max(maxi, x);
            }
        }
        else {
            if(mp[nums[0]]==1) maxi = max(maxi, nums[0]);
            if(mp[nums[n-1]]==1) maxi = max(maxi, nums[n-1]);
        }

        return maxi;
    }
};