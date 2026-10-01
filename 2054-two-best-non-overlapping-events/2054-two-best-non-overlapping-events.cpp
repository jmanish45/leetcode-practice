class Solution {
public:
    int n;
    int memo[100001][3];

    int nextevent(int l, int end, vector<vector<int>>& events) {
        int r = n-1;
        int ans = n + 1;
        while(l<=r) {
            int mid  = l + (r-l) / 2;
            if(events[mid][0]>end) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int solve(int i , int count, vector<vector<int>>& events) {
        if(i>=n || count==2) return 0;
        if(memo[i][count]!=-1) return memo[i][count];
        int next = nextevent(i+1, events[i][1], events);
        int take = events[i][2] + solve(next, count+1, events);
        int skip = solve(i+1, count, events);
        return memo[i][count] = max(take, skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        memset(memo, -1, sizeof(memo));
        sort(events.begin(), events.end());
        return solve(0, 0, events);
    }
};