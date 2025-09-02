class Solution {
public:
    bool ispalindrome(string s, int from, int to) {
        while(from < to ) {
            if(s[from]!=s[to]) return false;
            from++;
            to--;
        }
        return true;
    }
    void palindromes(int idx, string s, vector<vector<string>> &ans, vector<string> &parts) {
        if(idx==s.size()) {
            ans.push_back(parts);
            return;
        }
        for(int i = idx; i<s.size(); i++) {
            if(!ispalindrome(s, idx, i)) continue;
            parts.push_back(s.substr(idx, i-idx+1));
            palindromes(i+1, s, ans, parts);
            parts.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        palindromes(0, s, ans, parts);
        return ans;
    }
};