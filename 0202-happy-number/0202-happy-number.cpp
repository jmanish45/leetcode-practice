class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(n);
        while(1) {
            int sum = 0;

            while(n!=0) {
                sum+=((n%10)*(n%10));
                n=n/10;
            }
            n = sum;
            if(sum==1) return true;
            if(st.find(n)!=st.end()) {
                return false;
            }
            else {
                st.insert(n);
            }
        }
        return false;
    }
};
