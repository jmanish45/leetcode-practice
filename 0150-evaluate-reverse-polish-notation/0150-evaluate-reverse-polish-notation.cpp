class Solution {
public:
    int operate(string s1, string s2, string o) {
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        int result = 0;
        if(o=="+") result = n1+n2;
        else if(o=="-") result = n1-n2;
        else  if(o=="*") result = n1*n2;
        else result = n1/n2;
        return result;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string>st;

        for(int i=0; i<n; i++) {
            if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="-" || tokens[i]=="/") {
                    string n1 = st.top();
                    st.pop();
                    string n2 = st.top();
                    st.pop();
                    int r = operate(n2, n1, tokens[i]);
                    st.push(to_string(r));    
            }
            else  {
                st.push(tokens[i]);
            }
        }
        int ans = stoi(st.top());
        return ans;
    }

};