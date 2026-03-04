class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int spec = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ith(m, 0);
        vector<int> jth(n, 0);

        for(int i = 0; i<m; i++) {

            for(int j = 0; j<n; j++) {
                if(mat[i][j]==1) {
                    ith[i]++;
                    jth[j]++;
                }
            }
        }
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n ;j++) {
                if(mat[i][j]==1) {
                    if(ith[i]+jth[j]==2) spec++;
                }
            }
        }
        return spec;
    }
};