class Solution {
public:
    int n;
    int dp[51];
    unordered_set<string> st;
    int solve(int idx, string s) {
        if(idx>=n) {
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int minextra =  n+1;
        string currstr = "";
        for(int i=idx; i<n; i++) {
            currstr+=s[i];
            int currextra = 0;
            if(st.find(currstr)==st.end()) {
                currextra = currstr.length();
            }
            else currextra = 0;
            int nextextra  = solve(i+1, s);
            int totalextra = currextra + nextextra ;
            minextra = min(minextra, totalextra);
            
        }
        return dp[idx] = minextra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        for(string &word : dictionary) {
            st.insert(word);
        }
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, s);
        return ans;
    }
};