class Solution {
public:
    int m, n;
    int mod = 1e9+7;
    typedef long long ll;
    //memoisation : as the function return pair and it depends on two variables i & j so  2d vector for memoisation

    vector<vector<pair<ll, ll>>> dp;
    
    pair<ll, ll> solve(int i, int j,vector<vector<int>>& grid ) {

        
        if(i==m-1 && j==n-1) {
            return {grid[i][j], grid[i][j]} ;
        }

        if(dp[i][j]!=make_pair(LLONG_MIN, LLONG_MAX)) {
            return dp[i][j];
        }
        ll maxval = LLONG_MIN;
        ll minval = LLONG_MAX;
        //down side will produce one minprod and one maxprod we will take the one which makes the maximum product till here but alsop store the minimum product so tahat there is a hanace if gettig a negative nmber to maximise later 
        if(i+1<m) {
            auto [downmax,downmin] = solve(i+1, j, grid);
            maxval = max({maxval, grid[i][j]*downmax, grid[i][j]*downmin});
            minval = min({minval, grid[i][j]*downmax, grid[i][j]*downmin});
        }
        if(j+1<n) {
            auto [rightmax, rightmin] = solve(i, j+1, grid);
            maxval = max({maxval, grid[i][j]*rightmax, grid[i][j]*rightmin});
            minval = min({minval, grid[i][j]*rightmax, grid[i][j]*rightmin});
        }
        

        return dp[i][j] = {maxval, minval};


    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        

        //initialisation of dp 
        dp = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = solve(0, 0, grid);
        return (maxProd>=0) ? maxProd%mod : -1;
    }
};