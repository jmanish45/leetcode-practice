class Solution {
public:
    int m, n, nonobstacle, result ;
    vector<vector<int>> dir {{-1,0}, {0,-1}, {1,0}, {0,1}};
    void backtrack(vector<vector<int>>& grid, int i, int j, int count) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1) {
            return ;
        }
        if(grid[i][j]==2 ) {
            if(count==nonobstacle) {
                result++;
            }
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        for(auto& d : dir) {
            int ni = i+d[0];
            int nj = j+d[1];
            backtrack(grid, ni, nj, count+1);
        }
        grid[i][j]=temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        nonobstacle = 1 ; //as the first element whhich is the start point is also a nonsobstacle
        result = 0;
        int start_x = 0;
        int start_y = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0) {
                    nonobstacle++;
                }
                if(grid[i][j]==1) {
                    start_x = i;
                    start_y = j;
                    
                }
            }
        }
        backtrack(grid,start_x, start_y, 0 );
        return result;
    }
};