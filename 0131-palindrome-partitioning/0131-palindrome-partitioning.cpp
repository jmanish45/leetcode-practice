class Solution {
public:
    int n;
    vector<vector<string>> result;
    bool  isPalind(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;

    }
    void solve(string s, vector<string>& curr, int idx) {
        if(idx==n) {
            result.push_back(curr);
            return;
        }
        for(int i=idx; i<n; i++) {
            string p =  s.substr(idx, i-idx+1);
            if(isPalind(p)) {
                curr.push_back(p);
                solve(s, curr, i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> curr;
        solve(s, curr, 0);
        return result;
    }
};