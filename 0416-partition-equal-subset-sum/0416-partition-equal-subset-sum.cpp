class Solution {
public:
    int dp[201][100001];
    bool helper(int i, int target, int sum, vector<int>& nums) {
        if(sum>target) return false;
        
        if(i>=nums.size()) {
            if(sum == target) return true;
            else return false;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take = helper(i+1, target, sum+nums[i], nums);
        int skip = helper(i+1, target, sum, nums);
        return dp[i][sum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        for(int ele :nums) {
            sum+=ele;
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        return helper(0, target, 0, nums);
    }
};