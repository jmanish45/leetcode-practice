class Solution {
public:
    int m, n;
    bool solve(int i, int j , vector<vector<char>>& board, string& word, int p ) {
        if(p==word.size()) {
            return true;
        }
        if(i>=m || j>=n || i<0 || j<0 || board[i][j]=='$') {
            return false;
        }
        
        if(board[i][j]!=word[p]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '$';
        int right = solve(i,j+1,board, word, p+1);
        int left = solve(i, j-1, board, word, p+1);
        int up = solve(i-1, j, board, word, p+1);
        int down = solve(i+1, j,  board, word, p+1);
        
        bool found = right || left || up || down ;
        board[i][j] = temp;
        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j]==word[0]) {
                    if(solve(i, j,  board, word, 0)) return true;
                }
                
            }
        }
        return false;
    }
};