class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int totalreq = pow(2,k);
        //or  totalreq = 1<<k;
        unordered_set<string> st;
        for(int i = k; i<=s.length(); i++) {
            string str = s.substr(i-k, k) ;

            st.insert(str);
            if(st.size()>=totalreq) return true;
        }
        return false;
    }
};