class Solution {
public:
    int dp[501][501];
    int m, n;
    int solve(string word1, string word2, int i, int j) {
        if(i>=m) return n-j;
        if(j>=n) return m-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j] =  solve(word1, word2, i+1, j+1);
        else {
            int add = 1 + solve(word1, word2, i+1, j);
            int remove = 1 + solve(word1, word2, i, j+1);
            int replace = 1 + solve(word1, word2, i+1, j+1);

            return dp[i][j] = min(add, min(remove, replace));


        }
    }
    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();
        memset(dp, -1, sizeof(dp)) ;
        return solve(word1, word2, 0, 0);
    }
};