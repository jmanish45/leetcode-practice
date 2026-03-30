class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='X') {
            return;
        }
        board[i][j]='S';
        for(int k=0; k<4; k++) {
            int ni = i+dir[k][0];
            int nj = j+dir[k][1];
            if(ni>=0 && nj>=0 && ni<m && nj<n && board[ni][nj]=='O') {
                dfs(ni,nj,board);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
       //we will heck all the border rows and columsn if there is a 'O' then the dfs will be applied to the neighbour 'O' of it if present and they will be marksed as safe with replacing it with 'S';

        //Top Row
        for(int i=0; i<n; i++) {
            if(board[0][i]=='O') {
                dfs(0,i,board);
            }
        }

        //Bottom Row
        for(int i=0; i<n; i++) {
            if(board[m-1][i]=='O') {
                dfs(m-1,i,board);
            }
        }

        //Left column
        for(int i=0; i<m; i++) {
            if(board[i][0]=='O') {
                dfs(i,0,board);
            }
        }

        //Right column
        for(int i=0; i<m; i++) {
            if(board[i][n-1]=='O') {
                dfs(i, n-1, board);
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]=='S') {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }
        return;


    }
};