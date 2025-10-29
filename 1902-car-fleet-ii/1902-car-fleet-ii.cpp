class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<int> st;
        vector<double> time(n, -1);
        for(int i = n-1; i>=0; i--) {
            int pos_i = cars[i][0];
            int speed_i = cars[i][1];
            while(!st.empty()) {
                int j = st.top();
                int pos_j = cars[j][0];
                int speed_j = cars[j][1];
                if(speed_i <= speed_j) {
                    st.pop();
                    continue;
                }
                double t = (double)(pos_j - pos_i)/(speed_i -speed_j );
                if(time[j]>0 && t >= time[j]) {
                    st.pop();
                    continue;
                }
                time[i] = t;
                break;


            }
            st.push(i);


        }
        return time;
    }
};