class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visit(m, vector<int>(n,1));
        vector<vector<int>> dist(m, vector<int>(n,0));
        queue<pair<pair<int,int>, int>> q;
        for(int i = 0;i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j]==0) {
                    visit[i][j] = 0;
                    q.push({{i,j},0});
                } 
            }

        }
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            dist[row][col] = steps;
            q.pop();
            for(int i = 0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visit[nrow][ncol] == 1) {
                    visit[nrow][ncol] = 0;
                    q.push({{nrow, ncol}, steps + 1});

                }
            }
            
        }
        return dist;
    }
};