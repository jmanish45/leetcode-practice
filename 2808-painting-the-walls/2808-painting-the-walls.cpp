class Solution {
public:
    int n;
    int t[501][501];

    int solve(int idx, int remain, vector<int>& cost, vector<int>& time) {
        
        if(remain<=0) {
            return 0;       //this condition should be checked first so that if we can lso check for the next indexes further till idx<n
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
        memset(t, -1, sizeof(t));
        return solve(0, n, cost, time);
    }
};