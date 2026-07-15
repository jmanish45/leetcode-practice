class Solution {
public:
    int n;
    int dp[101];
    int solve(int i, string s) {
        if(dp[i]!=-1) return dp[i];
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        int result = solve(i+1,s);
        if(i+1<n) {
            if(s[i]=='1' || s[i]=='2' && s[i+1]<='6') {
                result+=solve(i+2,s);
            }
        }
        return dp[i]=result;
    }
    int numDecodings(string s) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};