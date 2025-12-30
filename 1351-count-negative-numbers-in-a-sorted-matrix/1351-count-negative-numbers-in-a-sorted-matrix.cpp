class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // [ 4, 3, 2,-1]
        // [ 3, 2, 1,-1]
        // [ 1, 1,-1,-2]
        // [-1,-1,-2,,-3]
        int m = grid.size();
        int n = grid[0].size();
        //starting from the lowest left cell
        int i = m-1;
        int j = 0;
        int count = 0;
        while(i>=0 && j<n) {
            if(grid[i][j]<0) {
                count +=(n-j);
                i--;
            }
            else {
                j++;
            }
        }
        return count ;
        
        
    }
};