class Solution {
public:
    int dp[501][501];

    int solve(string word1, string word2, int m, int n) {
        if(m<0) return n+1;
        if(n<0) return m+1;
        if(dp[m][n]!=-1) return dp[m][n];
        if(word1[m]==word2[n]) return dp[m][n] =  solve(word1, word2, m-1, n-1);
        else {
            int add = 1 + solve(word1, word2, m-1, n);
            int remove = 1 + solve(word1, word2, m, n-1);
            int replace = 1 + solve(word1, word2, m-1, n-1);

            return dp[m][n] = min(add, min(remove, replace));


        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        memset(dp, -1, sizeof(dp)) ;
        return solve(word1, word2, m-1, n-1);
    }
};