// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temp) {
//         int n = temp.size();
//         vector<int> ans(n, 0);
//         stack<int> st; 

//         for (int i = 0; i < n; i++) {
//             while (st.size()>0 && temp[i] > temp[st.top()]) {
//                 int idx = st.top();
//                 st.pop();
//                 ans[idx] = i - idx;
//             }
//             st.push(i);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> st; 

        for (int i = n-1; i>=0; i--) {
            while (st.size()>0 && temp[st.top()]<=temp[i]) {
                st.pop();
            }
            if(!st.empty()) {
                int idx = st.top();
                ans[i] = idx - i;
            }
            else {
                ans[i] = 0;
            }
            st.push(i);
        }

        return ans;
    }
};
