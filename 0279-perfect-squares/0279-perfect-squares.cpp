class Solution {
public:
        int dp[10001];
        //vector<int> dp;
        int solve(int n) {
            if(n==0) return 0;
            if(dp[n]!=-1) return dp[n];
            int minC = INT_MAX;
            for(int i=1; i*i<=n; i++) {
                int ans = 1 + solve(n-i*i);
                minC = min(minC, ans);
            }
            return dp[n] = minC;
        }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        //dp.resize(n+1,-1);
        return solve(n);
    }
};