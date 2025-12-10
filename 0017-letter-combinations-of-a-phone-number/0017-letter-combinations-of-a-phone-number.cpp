class Solution {
public:
    void solve(string digits, string output, vector<string>& ans, int idx, string mapping[] ){
        if(idx>=digits.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digits[idx] - '0';
        string value = mapping[number];
        for(int i = 0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, output, ans, idx+1, mapping);
            output.pop_back();
        }

    } 

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string output="";
        int idx = 0;
        string mapping[] = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, ans, idx, mapping) ;
        return ans;
    }
};