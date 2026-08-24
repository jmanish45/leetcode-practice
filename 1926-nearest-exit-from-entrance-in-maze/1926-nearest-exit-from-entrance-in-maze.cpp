class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    bool isValid(int i, int j,vector<vector<char>>& maze, vector<vector<int>>& visit) {
        return (i>=0 && i<m && j>=0 && j<n && maze[i][j]=='.' && visit[i][j]==0);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        visit[entrance[0]][entrance[1]] = 1;
        while(q.size()) {
            auto f = q.front();
            q.pop();
            
            if ((f[0] != entrance[0] || f[1] != entrance[1]) &&
            (f[0] == 0 || f[0] == m-1 || f[1] == 0 || f[1] == n-1)) {
                return f[2];
            }
            for(auto d : dir) {
                int ni = f[0] + d[0];
                int nj = f[1] + d[1];
                if(isValid(ni, nj, maze, visit)) {
                    q.push({ni,nj,f[2]+1});
                    visit[ni][nj] = 1;
                }
            }
        }
        return -1;
        
    }
};