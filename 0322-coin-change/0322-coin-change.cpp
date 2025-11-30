class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int helper(int idx, long long sum, int amount, vector<int>& coins) {
        if(idx==n) {
            if(sum==amount) return 0;
            else return INT_MAX;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        if(sum+coins[idx] > amount) {
            return dp[idx][sum] = helper(idx+1, sum, amount, coins);
        }
        else {
            long long take = 1LL + helper(idx, sum+coins[idx], amount, coins);
            long long leave = helper(idx+1, sum, amount, coins);
            return dp[idx][sum]  = min(take, leave);
        }
        
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.resize(n,  vector<int> (amount+1, -1));
        int ans = helper(0, 0, amount,coins);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};