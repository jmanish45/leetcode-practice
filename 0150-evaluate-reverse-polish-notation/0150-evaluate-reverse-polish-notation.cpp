class Solution {
public:
    int operate(int n1, int n2, string o) {
        int result = 0;
        if(o=="+") result = n1+n2;
        else if(o=="-") result = n1-n2;
        else  if(o=="*") result = n1*n2;
        else result = n1/n2;
        return result;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;

        for(int i=0; i<n; i++) {
            if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="-" || tokens[i]=="/") {
                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();
                    int r = operate(n2, n1, tokens[i]);
                    st.push(r);    
            }
            else  {
                st.push(stoi(tokens[i]));
            }
        }
        int ans = st.top();
        return ans;
    }

};