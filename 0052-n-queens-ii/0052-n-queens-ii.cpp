class Solution {
public:
    int result;
    int n;
    bool isSafe(int row, int col, vector<string>& board) {
        int ro = row;
        int co = col;
        while(col>=0) {
            if(board[row][col]=='Q') return false ;
            col--;
        }
        col = co;
        while(row>=0 && col>=0) {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row = ro;
        col = co;
        while(row<n && col>=0) {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col , vector<string>& board) {
        if(col==n) {
            result++;
            return ;
        }
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board)) {
                board[row][col] = 'Q';
                solve(col+1, board);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int N) {
        n = N;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++ ) {
            board[i] = s;
        }
        solve(0, board);
        return result;
    }
};