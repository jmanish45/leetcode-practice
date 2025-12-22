class Solution {
public:
    int m, n,  nonobstacles, result;
    vector<vector<int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    void backtrack(vector<vector<int>>& grid, int count,int i,int j) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1) {
            return ;
        }
        if(grid[i][j]==2) {
            if(count==nonobstacles) result++;
            return;
        }
        grid[i][j] = -1;
        for(auto& d : dir) {
            int new_i = i+d[0];
            int new_j = j+d[1];
            backtrack(grid, count+1, new_i, new_j);
        }
        grid[i][j] = 0;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        nonobstacles = 0;
        int start_x = 0;
        int start_y = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0) {
                    nonobstacles++;
                }
                if(grid[i][j]==1) {
                    nonobstacles++;
                    start_x = i;
                    start_y = j;
                }
            }
        }
        backtrack(grid, 0, start_x, start_y);
        return result;
    }
};