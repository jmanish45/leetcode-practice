class Solution {
public:
    int dp[46];
    int solve(int n) {
        if(n==0 || n==1) {
            return 1;
        }

        if(dp[n]!=-1) {
            return dp[n];
        }
        int climbOne = solve(n-1);
        int climbTwo = solve(n-2);
         
        return dp[n] = climbOne + climbTwo;
    }
    int climbStairs(int n) {
        memset(dp,-1, sizeof(dp));
        return solve(n); 

    }
};