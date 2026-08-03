class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int idx, vector<int>& nums) {
        if(idx==n-1) return 0;
        if(nums[idx]==0) return INT_MAX;
        if(dp[idx]!=-1) return dp[idx];
        int minj = INT_MAX;
        for(int i=1; i<=nums[idx]; i++) {
            if(idx+i < nums.size()) {
                int next = solve(idx+i, nums);
                if(next!=INT_MAX) minj = min(minj, next+1);
            }
        }
        return dp[idx] = minj;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return solve(0,nums);

    }
};