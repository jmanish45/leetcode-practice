class Solution {
public:
    int m;
    long long dp[100001];
    int nextpoint(int l, int end, vector<vector<int>>& rides) {
        int r = m-1;
        int ans = m+1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(rides[mid][0]>=end) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
    long long solve(int i, vector<vector<int>>& rides) {
        if(i>=m) return 0;
        if(dp[i]!=-1) return dp[i];
        int next = nextpoint(i+1, rides[i][1], rides);
        long long take = rides[i][1] - rides[i][0] + rides[i][2] + solve(next, rides);
        long long skip = solve(i+1, rides);
        return dp[i] = max(take, skip);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        m = rides.size();
        memset(dp, -1, sizeof(dp));
        sort(rides.begin(), rides.end());
        return solve(0, rides);
    }
};