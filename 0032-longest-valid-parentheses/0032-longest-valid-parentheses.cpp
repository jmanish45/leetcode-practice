class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        int maxi = 0;
        int i = 0;
        st.push(-1);
        while(i<n) {
            if(s[i]=='(') {
                st.push(i);
            }
            else {
                st.pop(); 
                if(st.empty()) {
                    st.push(i);
                }   
                else {
                    maxi = max(maxi, i - st.top());
                }
            }
            i++;
        }
        maxi = max(maxi, n-1 - st.top());
        return maxi;
    }
};