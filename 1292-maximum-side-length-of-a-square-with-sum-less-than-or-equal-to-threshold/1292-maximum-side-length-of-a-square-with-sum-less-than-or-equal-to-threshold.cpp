class Solution {
public:
    bool square(int i, int j, int ei, int ej, vector<vector<int>>& pref, int   threshold ) {
        int sum = 0;
        sum += pref[ei][ej];
        if(i>0) sum -= pref[i-1][ej];
        if(j>0) sum-= pref[ei][j-1];
        if(i>0 && j>0) sum+= pref[i-1][j-1];

        if(sum<=threshold) return true;
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pref(m, vector<int> (n,0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                pref[i][j] = ((i>0) ? pref[i-1][j] : 0) + ((j>0) ? pref[i][j-1] : 0) - ((i>0 && j>0) ? pref[i-1][j-1] : 0 ) + mat[i][j];
            }
        }
        int maxside = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                for(int k=maxside; k<min(m-i, n-j); k++) {
                    int ei = i+k;  //ending i (rightbottom corner of square)
                    int ej = j+k;   //ending j

                    if(square(i, j, ei, ej, pref, threshold)) {
                        maxside = max(maxside, k+1);
                    }
                }
            }
        }   
        return maxside;
    }
};