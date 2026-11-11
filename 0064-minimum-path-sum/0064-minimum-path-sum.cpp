class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //first row 
        for(int i = 1; i<n; i++) {
            grid[0][i] = grid[0][i]+grid[0][i-1];
        }
        
        //first column
        for(int i=1; i<m; i++) {
            grid[i][0] = grid[i][0]+grid[i-1][0];
        }
        
        for(int i = 1; i<m; i++) {
            for(int j=1; j<n; j++) {
                int val = grid[i][j];
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + val;
            }
        }
        return grid[m-1][n-1] ;
    }
};

// class Solution {
// public:
//     int m, n ;
//     int dp[201][201];
//     int solve(vector<vector<int>>& grid, int i, int j) {
        
//         if(i>=m || j>=n) {
//             return INT_MAX;
//         }
//         if(i==m-1 && j==n-1) {
//             return dp[i][j] = grid[i][j];
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         int down = solve(grid, i+1, j);
//         int right = solve(grid, i, j+1);
//         return dp[i][j] = grid[i][j] + min(down, right); 

//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         memset(dp, -1, sizeof(dp));
//         return solve(grid, 0, 0);
//     }
// };