class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visit, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]=='0' || visit[row][col]==1) {
            return;
        }
        
        visit[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()) {
             row = q.front().first;
             col = q.front().second;
            q.pop();
            bfs(row+1, col, visit, grid);
            bfs(row, col+1, visit, grid);
            bfs(row-1, col, visit, grid);
            bfs(row, col-1, visit, grid);
        }
 
    }
    int numIslands(vector<vector<char>>& grid) {
        int m  = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m, vector<int> (n,0));
        int count = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(visit[i][j]==0 && grid[i][j]=='1') {
                    count++;
                    bfs(i, j, visit,grid);
                }
            }
        }
        return count;
    }
};