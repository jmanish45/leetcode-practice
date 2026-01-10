class Solution {
public:
    int dp[500][500];
    int helper(string& word1, int m, string& word2, int n) {
        if(m<0) return n+1;
        if(n<0) return m+1;
        if(dp[m][n]!=-1) return dp[m][n];
        if(word1[m]==word2[n]) return dp[m][n] = helper(word1, m-1, word2, n-1);
        else {
            int add = 1 + helper(word1, m, word2,  n-1);
            int remove = 1 + helper(word1, m-1, word2, n);
            int replace = 1 + helper(word1, m-1, word2, n-1);
            return dp[m][n]=min(add, min(remove, replace));
        } 
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        memset(dp, -1, sizeof(dp));
        return helper(word1, m-1, word2, n-1);
    }
};