class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totsum = 0;
        int m = grid.size(); // m = 1 
        int n = grid[0].size(); // n = 3 
        for(int i = 0; i<m; i++) {  
            for(int j = 0; j<n; j++) {
                totsum+=grid[i][j];
            }
        }
        if(totsum%2!=0) return false;
        long long rowsum = 0;
        for(int i = 0; i< m; i++) {
            for(int j = 0; j<n; j++) {
                rowsum+=grid[i][j];
            }
            if(rowsum==totsum/2) return true;
            else if(rowsum>totsum/2) {
                break;
            };
        }
        long long colsum = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                colsum+=grid[j][i];
            }
            if(colsum==totsum/2) return true;
            else if(colsum>totsum/2) {
                break;
            };
        }

        return false;

    }
};