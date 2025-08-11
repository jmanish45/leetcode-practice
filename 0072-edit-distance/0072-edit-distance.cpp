class Solution {
public:
    vector<vector<int>> dp;
    int helper(string& a, int i, string& b, int j) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j] = helper(a, i-1, b, j-1);
        else {
            int add = 1 + helper(a, i, b, j-1);
            int remove = 1 + helper(a, i-1, b , j);
            int replace = 1 + helper(a, i-1, b, j-1);
            return dp[i][j] = min(add, min(remove, replace));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        dp.resize(m, vector<int>(n, -1));
        return helper(word1, m-1, word2, n-1);
    }
};