class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        stack<int> st;
        

        vector<bool> blast(n,0);
        for(int i = 0; i<n; i++) {
            while(!st.empty() && a[i]<0 && st.top()>0) {
                int atop = st.top();
                if(atop > -a[i]) {
                    blast[i] = 1;
                    break;
                }
                else if(atop == -a[i]) {
                    st.pop();
                    blast[i] = 1;
                    break;
                }
                else {
                    st.pop();
                }
                
            }
            if(blast[i]==0) {
                st.push(a[i]);
            }

            
        }
        while(!st.empty())  {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());



        return ans;
    }
};