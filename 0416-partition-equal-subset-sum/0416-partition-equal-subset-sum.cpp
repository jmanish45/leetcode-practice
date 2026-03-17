class Solution {
public:
    int dp[10001][201];
    bool solve(vector<int>& nums, int totsum , int idx) {
        if(totsum==0) {
        return  true; 
        }
        if(totsum<0 || idx>=nums.size()) {
            return  false;
        }
        if(dp[totsum][idx]!=-1) return dp[totsum][idx];
        int take = solve(nums, totsum-nums[idx], idx+1);
        int leave = solve(nums, totsum, idx+1);

        return dp[totsum][idx] = take || leave ;


    }
    bool canPartition(vector<int>& nums) {
        int totsum = 0;
        for(int i = 0; i<nums.size(); i++) {
            totsum+=nums[i];
        }
        if(totsum%2!=0) return false;
        memset(dp, -1, sizeof(dp));
        return solve(nums, totsum/2, 0);
    }
};