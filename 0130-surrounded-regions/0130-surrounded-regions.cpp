class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visit) {
        visit[row][col] = 1;
        int m = board.size();
        int n  = board[0].size();
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for(int i = 0; i<4 ; i++) {
            int nrow = row + drow[i];
            int ncol = dcol[i] + col;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O' && visit[nrow][ncol]==0 ) {
                dfs(nrow, ncol, board, visit);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visit(m, vector<int> (n,0));
        //traverse first row and last row
        for(int  j = 0; j<n; j++) {
            //first row 
            if(board[0][j]=='O' && visit[0][j]==0) {
                dfs(0, j, board, visit);
            }
            //last row
            if(board[m-1][j]=='O' && visit[m-1][j]==0) {
                dfs(m-1, j, board, visit);
            }
        }
        //traverse first and last column
        for(int i = 0; i<m; i++) {
            if(board[i][0]=='O' && visit[i][0]==0) {
                dfs(i, 0, board, visit);
            }
            if(board[i][n-1]=='O' && visit[i][n-1]==0) {
                dfs(i, n-1, board, visit);
            }
        }
        for(int i = 0; i<m ;i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j]=='O' && !visit[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

    }
};