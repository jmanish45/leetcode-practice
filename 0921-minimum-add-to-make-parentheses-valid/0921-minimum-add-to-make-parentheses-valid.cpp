// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         stack<char> st;
//         int open = 0;
//         int close = 0;
//         for(int i = 0 ; i < s.length(); i++) {
//             if(s[i]== '(') {
//                 open++;
//                 st.push(s[i]); 
//             }
//             else {
//                 if(open>0) {
//                    st.pop();
//                    open--;

//                 }
//                 else {
//                     close++;
//                     st.push(s[i]);
//                 }
//             }
//         }
//         return open + close;
//     }
// };
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        for(char c:s) {
            if(c=='(') {
                open++;
            }
            else {
                if(open>0) open--;
                else close++;
            }
        }
        return open + close;
    }
};