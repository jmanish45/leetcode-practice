class Solution {
public:
    int n ;
    vector<string> res;
    unordered_map<string, int> mp;
    int minInvalid(string s) {
        int i = 0;
        stack<char> st;
        while(i<s.size()) {
            if(s[i]=='(') st.push('(');
            else if(s[i]==')') {
                if(st.size()>0 && st.top()=='(') st.pop();
                else st.push(')');
            }
            i++;
        }
        return st.size();
    }
    void solve(string s, int m) {
        if(mp[s]>0) return;
        else mp[s]++;
        if(m<0) return ;
        if(m==0) {
            if(!minInvalid(s)) {
                res.push_back(s);
            }
            return ;
        }
        for(int i = 0; i<s.size(); i++) {
            if(s[i] != '(' && s[i] != ')') continue;
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right, m-1);
        }
         
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        int m = minInvalid(s);
        solve(s, m);
        return res;
    }
};