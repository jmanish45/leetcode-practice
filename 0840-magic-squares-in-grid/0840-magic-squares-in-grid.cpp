class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& grid) {
        int val = grid[i][j];
        if(val>9 || val<1) return false;
        int topleft = grid[i-1][j-1];
        if(val==topleft || topleft>9 || topleft<1) return false;
        int top = grid[i-1][j];
        if(val==top || top>9 || top<1) return false;
        int topright = grid[i-1][j+1];
        if(val==topright || topright>9 || topright<1) return false;
        int left  = grid[i][j-1];
        if(val==left || left>9 || left<1) return false;
        int right  = grid[i][j+1];
        if(val==right || right>9 || right<1) return false;
        int botmleft = grid[i+1][j-1];
        if(val==botmleft || botmleft>9 || botmleft<1) return false;
        int botm = grid[i+1][j];
        if(val==botm  || botm>9 || botm<1) return false;
        int botmright = grid[i+1][j+1];
        if(val==botmright || botmright>9 || botmright<1) return false;

        int upper = topleft + top + topright;
        int leftside = topleft + left + botmleft ;
        int lower = botmleft + botm + botmright;
        int rightside = botmright + right + topright;
        int midrow = left + val + right;
        int midcol = top + val + botm;
        int diag1 = topleft + val + botmright;
        int diag2 = topright + val + botmleft;

        if(upper!=leftside || upper!=lower || upper!=rightside || upper!=midrow || upper!=midcol || upper!=diag1 || upper!=diag2) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 1 ; i<m-1; i++) {
            for(int j=1; j<n-1; j++) {
                if(solve(i, j, grid)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};