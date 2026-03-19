// class Solution {
// public:
//     int n;
//     vector<vector<int>> dp;

//     int solve(int i, int j, vector<vector<int>>& triangle) {

//         if(i == n-1) return triangle[i][j];

//         if(dp[i][j] != -1) return dp[i][j];

//         int down = solve(i+1, j, triangle);
//         int diag = solve(i+1, j+1, triangle);

//         return dp[i][j] = triangle[i][j] + min(down, diag);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         n = triangle.size();
//         dp.resize(n, vector<int>(n, -1));
//         return solve(0, 0, triangle);
//     }
// };

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        //we will start from last row and geneating all the possible paths but taking only the minimum costly one by selecting from the two options 

        vector<int> dp = triangle[n-1];  //last row
        // dp = 4, 1, 8, 3

        for(int i=n-2; i>=0 ; i--) {
            for(int j=0; j<triangle[i].size(); j++) {
               dp[j] = triangle[i][j] + min(dp[j], dp[j+1]) ;
            }
        }

        return dp[0];

    }
};