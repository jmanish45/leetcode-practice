class Solution {
public:
    void  solve(string digits, vector<string>& ans, string s, int idx, vector<string> map) {
        if(idx>=digits.length()) {
            ans.push_back(s);
            return;
        }
        int num = digits[idx]- '0';
        string value = map[num];
        for(int i=0; i<value.length(); i++) {
            s.push_back(value[i]);
            solve(digits, ans, s, idx+1, map);
            s.pop_back();
        }

        

    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        string s = "";
        int idx = 0;
        vector<string> map = {"", "", "abc", "def", "ghi" , "jkl", "mno", "pqrs", "tuv", "wxyz"} ;
        solve(digits, ans, s,  idx, map);
        return ans;
    }
};