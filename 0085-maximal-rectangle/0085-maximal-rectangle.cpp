class Solution {
public:
    int m, n, maxarea;
    int solve(vector<int>& helper) {   //this  function relates to the question Largest Rectangle in histogram LC QUE 84
        vector<int> nsi(n);
        nsi[n-1] = n;
        stack<int> sn;
        sn.push(n-1);
        for(int i=n-2; i>=0 ; i--) {
            while(sn.size()>0 && helper[sn.top()]>=helper[i]) sn.pop();
            if(sn.size()==0) nsi[i] = n;
            else nsi[i] = sn.top(); 
            sn.push(i);
        }
        vector<int> psi(n);
        psi[0] = -1;
        stack<int> sp;
        sp.push(0);
        for(int i=1; i<n; i++) {
            while(sp.size()>0 && helper[sp.top()]>=helper[i]) sp.pop();
            if(sp.size()==0) psi[i] = -1;
            else psi[i] = sp.top();
            sp.push(i);
        }
        int maxa = 0; 
        for(int i=0; i<n; i++) {
            int height = helper[i];
            int width = nsi[i]-psi[i]-1;
            int area = height*width;
            maxa = max(area, maxa);
        }
        return maxa;

    }
    int maximalRectangle(vector<vector<char>>& mat) {
        m = mat.size();
        n = mat[0].size();
        maxarea = 0;
        vector<int> helper (n, 0);

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j]=='0') helper[j] = 0;
                else helper[j]+=1;    
            }
            int currarea = solve(helper);
            maxarea = max(currarea, maxarea);
            
        }
        return maxarea;

    }
};