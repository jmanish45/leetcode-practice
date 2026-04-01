class Solution {
public:
    int n;
    vector<int> dp;
    bool solve(int idx, vector<int>& nums) {
        if(idx==n-1) return true;
        if(dp[idx]!=-1) return dp[idx];
        bool can = false;
        if(nums[idx]>=((n-1)-idx)) return true;
        for(int i=1; i<=nums[idx]; i++) {
            can = can || solve(idx+i, nums);
        }
        return dp[idx] = can;

    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return solve(0, nums);

    }
};