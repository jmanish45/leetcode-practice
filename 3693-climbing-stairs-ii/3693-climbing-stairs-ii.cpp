class Solution {
public:
    vector<int> dp;
    int solve(int n, vector<int>& costs, int i) {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int j=1; j<=3; j++) {
            
            if(i+j<=n) {
                int cost = costs[i+j-1] + j*j +  solve(n,costs, i+j) ;
                ans = min(ans, cost);
            }
            
        }
        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        dp.resize(n, -1);
        return solve(n, costs, 0);
    }
};