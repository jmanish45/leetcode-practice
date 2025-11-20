class Solution {
public:
    int n;
    vector<vector<int>> t;
        // idx tells where we are.
        // remain tells how much is left.
        // Together they uniquely define the subproblem.
        // That’s why t[idx][remain] is the DP state.

    int solve(int idx, int remain, vector<int>& cost, vector<int>& time) {
        
        if(remain<=0) {
            return 0;       
        }
        if(idx>=n) {
            return 100000000001;
        }
        if(t[idx][remain]!=-1) return t[idx][remain];
        int paint_this = cost[idx] + solve(idx+1, remain-1-time[idx], cost, time);
        int dont_paint = 0 + solve(idx+1, remain-0, cost, time);

        return t[idx][remain] = min(paint_this, dont_paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        n = cost.size();
        t.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, n, cost, time);
    }
};