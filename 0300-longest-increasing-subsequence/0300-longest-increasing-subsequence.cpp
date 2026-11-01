class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int prev, int curr, vector<int>& nums) {
        if(curr==n) return 0;
        if(prev!=-1 && dp[prev][curr]!=-1) return dp[prev][curr];
        int take = 0;
        if(prev==-1 || nums[prev]<nums[curr]) {
            take = 1 + solve(curr, curr+1, nums);
        }
        int skip = solve(prev, curr+1, nums);
        if(prev!=-1) return dp[prev][curr]=max(skip, take);
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, vector<int>(n,-1));
        return solve(-1,0,nums);
    }
};