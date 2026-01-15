class Solution {
public:
    int solve(vector<int>& helper) {
        int mxa = 0;
        int n = helper.size();
        vector<int> nsi(n);
        stack<int> ns;
        ns.push(n-1);
        nsi[n-1] = n;
        for(int i=n-2; i>=0; i--) {
            while(ns.size()>0 && helper[ns.top()]>=helper[i]) ns.pop();
            if(ns.size()==0) nsi[i] = n;
            else nsi[i] = ns.top();
            ns.push(i);
        }
        vector<int> psi(n);
        stack<int> ps;
        psi[0] = -1;
        ps.push(0);
        for(int i= 1; i<n ;i++) {
            while(ps.size()>0 && helper[ps.top()]>=helper[i]) ps.pop();
            if(ps.size()==0) psi[i] = -1;
            else psi[i]  = ps.top();
            ps.push(i);
        } 
        for(int i = 0; i<n ; i++) {
            int height = helper[i];
            int width = nsi[i] - psi[i] - 1;
            int side = min(height, width);
            int area = side*side;
            mxa = max(mxa, area);
        }
        return mxa;

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxarea = 0;
        vector<int> helper(n, 0);
        for(int i = 0; i<m ;i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]=='0') helper[j]=0;
                else helper[j]+=1;
            }
            int currarea = solve(helper);
            maxarea = max(currarea, maxarea);
        }
        return maxarea;
    }
};