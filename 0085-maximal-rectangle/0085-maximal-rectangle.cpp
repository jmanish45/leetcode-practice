class Solution {
public:
    int m, n, ma;
    int solve(vector<int>& h) {   //this  function relates to the question Largest Rectangle in histogram LC QUE 84
        vector<int> nsi(n);
        nsi[n-1] = n;
        stack<int> sn;
        sn.push(n-1);
        for(int i=n-2; i>=0 ; i--) {
            while(sn.size()>0 && h[sn.top()]>=h[i]) sn.pop();
            if(sn.size()==0) nsi[i] = n;
            else nsi[i] = sn.top(); 
            sn.push(i);
        }
        vector<int> psi(n);
        psi[0] = -1;
        stack<int> sp;
        sp.push(0);
        for(int i=1; i<n; i++) {
            while(sp.size()>0 && h[sp.top()]>=h[i]) sp.pop();
            if(sp.size()==0) psi[i] = -1;
            else psi[i] = sp.top();
            sp.push(i);
        }
        int maxa = 0; 
        for(int i=0; i<n; i++) {
            int height = h[i];
            int width = nsi[i]-psi[i]-1;
            int area = height*width;
            maxa = max(area, maxa);
        }
        return maxa;

    }
    int maximalRectangle(vector<vector<char>>& mat) {
        m = mat.size();
        n = mat[0].size();
        ma = 0;
        vector<int> h (n, 0);

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j]=='0') h[j] = 0;
                else h[j]+=1;    
            }
            int currarea = solve(h);
            ma = max(currarea, ma);
            
        }
        return ma;

    }
};