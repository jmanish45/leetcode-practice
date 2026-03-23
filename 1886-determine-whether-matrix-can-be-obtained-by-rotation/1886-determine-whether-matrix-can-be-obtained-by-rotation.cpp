class Solution {
public:
    int m, n;
    void rotate(vector<vector<int>>& mat) {

        //taking transpose
        for(int i = 0; i<m; i++) {
            for(int j=i; j<n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        //reversing the rows elements

        for(int i = 0; i<n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }

    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        m = mat.size();
        n = mat[0].size();
        if(mat==target) return true;;
        for(int i = 0; i<3; i++) {
            rotate(mat);
            if(mat==target) return true;
        }
        return false;

    }
};