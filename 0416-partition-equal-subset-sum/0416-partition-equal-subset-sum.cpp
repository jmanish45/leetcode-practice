class Solution {
public:
    int n;
    int dp[201][10001];
    bool solve(int idx, vector<int>& nums, int totsum) {
        if(totsum==0) return true;
        if(totsum<0 || idx==n) return false;
        if(dp[idx][totsum]!=-1) return dp[idx][totsum];
        
        int take = solve(idx+1, nums, totsum-nums[idx]);
        int leave = solve(idx+1, nums, totsum);

        return dp[idx][totsum] = take || leave;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int totsum = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++) {
            totsum+=nums[i];
        }
        if(totsum%2!=0) return false;
        return solve(0, nums, totsum/2);
     }
};