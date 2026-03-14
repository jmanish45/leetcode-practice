class Solution {
public:
    int t[1001];
    int solve(int idx , vector<int>& cost) {

        if(idx>=cost.size()) {
            return 0;
        }
        if(t[idx]!=-1) return t[idx];
        int onestep = cost[idx] + solve(idx+1, cost) ;
        int twostep = cost[idx] + solve(idx+2, cost);

        return t[idx] = min(onestep, twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));
        return min(solve(0, cost), solve(1, cost));


    }
};