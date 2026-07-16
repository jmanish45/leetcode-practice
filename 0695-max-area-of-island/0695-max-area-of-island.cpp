class Solution {
public:
    int m;
    int n;

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;

        return 1 +
               dfs(i, j-1, grid) + dfs(i, j+1, grid) + dfs(i-1, j, grid) + dfs(i+1, j, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }

        return maxArea;
    }
};