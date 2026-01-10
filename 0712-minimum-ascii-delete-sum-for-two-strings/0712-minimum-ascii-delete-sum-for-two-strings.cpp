class Solution {
public:
    int dp[1000][1000];
    int lcs(string& s1, int m, string& s2, int n) {
        if(m==0 || n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m-1]==s2[n-1]) {
            return dp[m][n] = lcs(s1, m-1, s2, n-1) + int(s1[m-1]);
        }
        else {
            return dp[m][n] = max(lcs(s1, m-1, s2, n), lcs(s1, m, s2, n-1));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        //we will take totalsum of all the characters ascii numbers
        //then we with the help of recursion we can check for the maximum possible common substring which is common in both the strings
        //then we will find the answer by subtracting the sum of ascii values of common substrings from the totalsum 
        int totalsum = 0;
        memset(dp, -1, sizeof(dp));
        for(char c : s1) totalsum+= int(c);
        for(char c : s2) totalsum+= int(c);

        int commonsum = lcs(s1,l1, s2,l2);
        return totalsum - 2*(commonsum);

    }
};