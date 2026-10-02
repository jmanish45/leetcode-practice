class Solution {
public:
    void generate(string s,vector<string>& v, int open, int close, int n) {
        if(close==n) {
            v.push_back(s);
            return ;
        }
        if(open<n) generate(s+"(", v, open+1, close, n);
        if(close<open) generate(s+")", v, open, close+1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generate("", v, 0, 0, n) ;
        return v; 
    }
};