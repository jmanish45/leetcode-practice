class Solution {
public:
    bool ispalindrome(string s) {
        int n = s.length();
        int i=0;
        int j = n-1;
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    void palindromes(string s, vector<vector<string>> &ans, vector<string> &parts) {
        if(s.size()==0) {
            ans.push_back(parts);
            return;
        }
        for(int i = 0; i<s.size(); i++) {
            string part = s.substr(0, i+1);
            if(ispalindrome(part)) {
                parts.push_back(part);
                palindromes(s.substr(i+1), ans, parts);
                parts.pop_back();
            }
            
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        palindromes( s, ans, parts);
        return ans;
    }
};