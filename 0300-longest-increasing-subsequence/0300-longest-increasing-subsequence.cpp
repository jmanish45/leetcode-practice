class Solution {
public:
    int dp[2501][2501];
    int solve(int idx, int prev, vector<int>& nums) {
        if(idx>=nums.size()) return 0;
        if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev] ;
        int take = 0;
        if(prev==-1 || nums[prev]<nums[idx] ) {
            take = 1 + solve(idx+1, idx, nums);
        }
        int skip = solve(idx+1, prev, nums);
        if(prev!=-1) dp[idx][prev] = max(skip, take);
        return  max(skip, take) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0,-1, nums);
    }
};