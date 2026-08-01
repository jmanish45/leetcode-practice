class Solution {
public:
    int s;
    int dp[601][101][101];
    vector<int> count(string str) {
        int zero = 0;
        int ones = 0;
        for(int i=0; i<str.length(); i++) {
            if(str[i]=='1') ones++;
            else zero++;
        }
        return {zero, ones};
    }
    int solve(vector<string>& strs, int idx ,int m, int n) {
        if(idx==s) {
            return 0;
        }
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        vector<int> mj = count(strs[idx]);
        int z = mj[0];
        int o = mj[1];
        if(z>m || o>n) {
            return dp[idx][m][n] = solve(strs, idx+1, m, n);
        }
        else {
            int take = 1 + solve(strs, idx+1, m-z, n-o);
            int leave = solve(strs, idx+1, m, n);
            return dp[idx][m][n] = max(leave, take);
        }
        
        
        return 0;    
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        s = strs.size();
        memset(dp, -1, sizeof(dp));
        return solve(strs,0, m , n );
        
    }
};