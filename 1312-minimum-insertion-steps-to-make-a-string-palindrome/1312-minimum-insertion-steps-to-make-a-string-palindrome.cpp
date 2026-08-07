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
    int longestPalindromeSubseq(string s) {
        string b = s;
        reverse(b.begin(), b.end());
        int m = s.length();
        dp.resize(m, vector<int> (m, -1));
        return lcs(s, m-1, b , m-1);
    }
    int minInsertions(string s) {
        int n = s.length();
        return n - longestPalindromeSubseq(s);
    }
};