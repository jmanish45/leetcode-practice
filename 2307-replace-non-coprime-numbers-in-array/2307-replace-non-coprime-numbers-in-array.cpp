class Solution {
public:
    int lcm(int a, int b) { 
        if(b>a) return lcm(b,a);
        int t = b;
        while(b%a!=0) {
            b+=t;   
        }
        return b;
    }
    int gcd(int a , int b) {
        while(b!=0) {
            int t = b; 
            b = a % b;
            a = t;
        }
        return a;
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(nums[0]);
        for(int i = 1; i<n; i++) {
            int curr = nums[i];
            while(!st.empty()  && gcd(curr, st.top())>1) {
                curr = lcm(curr, st.top());
                st.pop();
            }
            st.push(curr);
            
        }
        vector<int> ans;
        while(!st.empty()) {
            int tp = st.top();
            st.pop();
            ans.push_back(tp);
        }
        reverse(ans.begin(),  ans.end());
        return ans;
    }
};