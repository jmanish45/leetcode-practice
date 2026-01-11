class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsi(n); 
        stack<int> st;  //next smaller index
        nsi[n-1] = n;
        st.push(n-1);
        for(int i=n-2; i>=0; i--) {
            while(st.size()>0 && heights[st.top()]>=heights[i]) st.pop();
            if(st.size()==0) nsi[i] = n;
            else nsi[i]=st.top();
            st.push(i);   
        }

        vector<int> psi(n);
        stack<int> pt;
        psi[0] = -1;
        pt.push(0);
        for(int i=1; i<n; i++) {
            while(pt.size()>0 && heights[pt.top()]>=heights[i]) pt.pop();
            if(pt.size()==0) psi[i] = -1;
            else psi[i] = pt.top();
            pt.push(i);
        }

        int maxarea = 0;
        for(int i=0;  i<n; i++) {
            int height = heights[i];
            int base = nsi[i]-psi[i]-1;
            int area = height*base;
            maxarea = max(area, maxarea);
        }
        return maxarea;

    }
};