class Solution {
public:
    int n;
    bool  isvalid(vector<vector<int>>& grid, int r, int c, int expValue ) {
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expValue) return false;
        if(expValue == n*n - 1) return true;

        int mov1 = isvalid(grid, r-2, c+1, expValue+1);
        int mov2 = isvalid(grid, r-2, c-1, expValue+1);
        int mov3 = isvalid(grid, r-1, c-2, expValue+1);
        int mov4 = isvalid(grid, r+1, c-2, expValue+1);
        int mov5 = isvalid(grid, r+2, c-1, expValue+1);
        int mov6 = isvalid(grid, r+2, c+1, expValue+1);
        int mov7 = isvalid(grid, r+1, c+2, expValue+1);
        int mov8 = isvalid(grid, r-1, c+2, expValue+1);

        return mov1 || mov2 || mov3 || mov4 || mov5 || mov6 || mov7 || mov8;



    }
    bool checkValidGrid(vector<vector<int>>& grid) {
       n = grid.size();
       return isvalid(grid, 0, 0, 0); 
    }
};