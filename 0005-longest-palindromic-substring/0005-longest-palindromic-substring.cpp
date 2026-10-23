class Solution {
public:
    int dp[1001][1001];
    bool check(int i, int j, string &s) {
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = check(i+1, j-1, s);
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int m = s.length();
        memset(dp,-1,sizeof(dp));
        int maxlen = 0;
        int start = 0;
        for(int i=0; i<m; i++) {
            for(int j=i; j<m; j++) {
                if(check(i,j,s)) {
                    if((j-i+1)>maxlen) {
                        maxlen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};