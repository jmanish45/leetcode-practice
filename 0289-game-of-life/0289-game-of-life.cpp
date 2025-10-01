class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> v(m,vector<int>  (n,0));
        vector<vector<int>> neigh(m, vector<int> (n,0));
        for(int i = 0 ; i<m ; i++){
            for(int j = 0; j<n ; j++) {
                v[i][j] = board[i][j];
                int sum = 0;
                for(int dx=-1;dx<=1;dx++) {
                    for(int dy=-1;dy<=1;dy++) {
                        if(dx==0 && dy==0)  continue;
                        int x = i+dx;
                        int y = j + dy;
                        if(x>=0 && x<m && y>=0 &&  y<n) {
                            sum+=board[x][y];
                        }
                    }
                }
                neigh[i][j] = sum;
            }
        }
        for(int i = 0; i<m;i++) {
            for(int j = 0; j<n; j++) {
                if(v[i][j]==0) {
                    if(neigh[i][j]==3) {
                        board[i][j]=1;
                    }
                    else board[i][j] = 0;
                }
                else {
                    if(neigh[i][j]<2) {
                        board[i][j] = 0;
                    }
                    else if(neigh[i][j]>3) {
                        board[i][j] = 0;
                    }
                    else board[i][j] = 1;
                }
            }

        }
        return ;

    }
};