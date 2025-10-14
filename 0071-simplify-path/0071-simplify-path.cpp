class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        int i = 0;
        
        while (i < n) {
            while (i < n && path[i] == '/') i++;
            if (i >= n) break;
            
            
            string s = "";
            while (i < n && path[i] != '/') {
                s += path[i];
                i++;
            }
            
            
            if (s == "..") {
                if (!st.empty()) st.pop();
            } else if (s != "." && !s.empty()) {
                st.push(s);
            }
        }
        
        
        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        return ans.empty() ? "/" : ans;
    }
};
