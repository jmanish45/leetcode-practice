class Solution {
public:
    vector<vector<int>> dp;
    
    int lcs(string &s1, int m, string &s2, int n) {
        if (m == 0 || n == 0) return 0;  // no ASCII sum if one string is empty
        if (dp[m][n] != -1) return dp[m][n];
        
        if (s1[m-1] == s2[n-1]) {
            // Add ASCII value of the matching char
            return dp[m][n] = lcs(s1, m-1, s2, n-1) + (int)s1[m-1];
        } else {
            return dp[m][n] = max(lcs(s1, m-1, s2, n), lcs(s1, m, s2, n-1));
        }
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int w1 = s1.size(), w2 = s2.size();
        dp.assign(w1+1, vector<int>(w2+1, -1));
        
        int totalSum = 0;
        for (char c : s1) totalSum += (int)c;
        for (char c : s2) totalSum += (int)c;
        
        int commonSum = lcs(s1, w1, s2, w2);
        return totalSum - 2 * commonSum;
    }
};
