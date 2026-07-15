class Solution {
public:
    typedef long long ll;
    vector<vector<int>> dp;
    int n;
    int solve(int idx, vector<int>& coins, int amount) {
        if(idx==n) {
            if(amount==0) return 0;
            else return INT_MAX;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        if((amount-coins[idx])<0) {
            return solve(idx+1, coins, amount);
        }
        else {
            ll take = (ll)1 + solve(idx, coins, amount-coins[idx]);
            ll leave = solve(idx+1, coins, amount);
            return dp[idx][amount] = min(take, leave);
        }

        
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.resize(n, vector(amount+1, -1));
        int ans =  solve(0, coins, amount);
        return ans==INT_MAX ? -1 : ans;
    }
};