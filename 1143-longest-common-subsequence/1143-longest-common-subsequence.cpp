class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int  j, string &s1, string &s2) {
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) {
            return dp[i][j] = 1 + solve(i-1, j-1, s1, s2);
        }
        
        int a = solve(i-1, j, s1, s2);
        int  b = solve(i, j-1, s1, s2);
        return dp[i][j] = max(a, b);
    }

    int longestCommonSubsequence(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        dp.resize(m, vector<int>(n, -1));
        return solve(m-1, n-1, s1, s2 );

    }
};