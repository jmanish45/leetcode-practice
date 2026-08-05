class Solution {
public:
    int m, n;
    int t[101][101];
    bool vis[101][101]; 
    int solve(int row , int col ,vector<vector<int>>& matrix) {
        if(row==m-1) return matrix[row][col];
        if(vis[row][col]) return t[row][col];
        vis[row][col] = true;

        
        int result = INT_MAX;
        int sum = matrix[row][col];
        if(row+1<m && col+1<n)
            result = min(result, sum+solve(row+1, col+1, matrix));
        if(row+1<m)
            result = min(result, sum+solve(row+1, col, matrix));
        if(row+1<m && col-1>=0)
            result = min(result, sum+solve(row+1, col-1, matrix));
        
        return t[row][col] = result;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = INT_MAX;
        memset(vis,false,sizeof(vis));
        int row = 0;
        for(int col = 0; col < n; col++) {
            ans = min(ans, solve(row, col , matrix));
        }
        return ans;
    }
};