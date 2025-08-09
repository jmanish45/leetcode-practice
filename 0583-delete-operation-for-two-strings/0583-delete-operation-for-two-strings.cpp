class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string &s1, int m, string &s2, int n) {
        if(m<0 || n<0) {
            return 0;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m]==s2[n] ) {
            return dp[m][n] = 1 + lcs(s1, m-1, s2, n-1);
        }
        else {
            return dp[m][n] = max(lcs(s1, m-1, s2, n) ,lcs(s1, m, s2, n-1));
        }
        
    }
    int minDistance(string word1, string word2) {
        
        
        int w1 = word1.size();
        int w2 = word2.size();
        dp.resize(w1, vector<int> (w2, -1));
        int a = lcs(word1, w1-1, word2, w2-1);
        int b = w1 - a;
        int c = w2 - a;
        return b + c;
    }
};