class Solution {
public:
    int calculate(string s) {
        int n = s.length();  // n = 5
        int  number = 0;
        int sign = 1;
        int result = 0;
        stack<int> st;
        for(int i = 0; i<n; i++) {
            if(isdigit(s[i])) {
                number = number*10 + (s[i]-'0');
            }
            else if(s[i]=='+') {
                result += number*sign;
                number = 0;
                sign = 1;
            }
            else if(s[i]=='-') {
                result += number*sign;
                number = 0;
                sign = -1;
            }
            else if (s[i]=='(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            }
            else if(s[i]==')') {
                result+= (number*sign);
                int top_sign = st.top();
                st.pop();
                int last_result = st.top();
                st.pop();
                
                result *= top_sign;
                result+=last_result;
                number = 0;
                
            }
        }
        //last element 
        result+=(number*sign);
        return result;
    }
};