class Solution {
public:
    int n ;
    vector<vector<int>> dp;
    int solve(int curr, int prev, vector<int>& nums) {
        if(curr==n) return 0;
        int take = 0;
        if(prev!=-1 && dp[curr][prev]!=-1) return dp[curr][prev];
        if(prev==-1 || nums[prev]<nums[curr]) {
            take = 1 + solve(curr+1, curr, nums);
        }
        int skip = solve(curr+1, prev, nums);
        if(prev!=-1) dp[curr][prev] =  max(take, skip);
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, vector<int>(n,-1));
        return solve(0, -1, nums);
    }
};