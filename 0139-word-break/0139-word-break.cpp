class Solution {
public:
    int  n;
    int dp[301];
    unordered_set<string> st;
    bool solve(int idx, string s) {
        if(idx>=n) {
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        if(st.find(s)!=st.end()) return true;

        for(int l = 1; l<=n; l++) {
            string temp = s.substr(idx, l);
            if(st.find(temp)!=st.end() && solve(idx+l,s)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& words) {
        for(auto& word : words) {
            st.insert(word);
        }
        memset(dp, -1, sizeof(dp));
        n = s.length();
        return solve(0, s);
    }
};