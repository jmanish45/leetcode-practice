class Solution {
public:
    int n;
    int t[2][101][101];
    int solve(vector<int>& piles, bool alice, int i, int M) {
        // bool alice tells if the turn is for alice 
        // i-> is the index on the piles
        // M -> max stones can be taken
        if(i>=n) return 0; // no stone will be added when i = n
        if(t[alice][i][M]!=-1) return t[alice][i][M];
        int result = (alice==1) ? -1 : INT_MAX;
        //initialise result = -1 to get Max from stones 
        //initialise result = INT_MAX to get min from 
        int stones = 0; //starting stones from 0
        
        //now choose the X to get number of stones in your turn 
        for(int x=1; x<=min(2*M,n-i); x++) {
            //adding the stones first 
            stones+=piles[i+x-1];
            if(alice) {
                result = max(result, stones + solve(piles, 0, i+x, max(M,x)));

            }
            else {
                result = min(result, solve(piles,1,i+x,max(M,x)));
            }
        }
        return t[alice][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        return solve(piles, 1, 0, 1);
    }
};