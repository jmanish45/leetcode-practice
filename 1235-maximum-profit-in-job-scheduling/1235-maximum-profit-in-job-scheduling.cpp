class Solution {
public:
    int n;
    int memo[50001];
    int nextjob(int l, int end, vector<vector<int>>& jobs) {
        int r = n-1;
        int ans = n+1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(jobs[mid][0]>=end) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int solve(int i, vector<vector<int>>& jobs) {
        if(i>=n) return 0;
        if(memo[i]!=-1) return memo[i];
        int next = nextjob(i+1, jobs[i][1], jobs);
        int take = jobs[i][2] + solve(next, jobs);
        int skip = solve(i+1, jobs);
        return memo[i] = max(skip, take);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pft) {
        n = st.size();
        memset(memo, -1, sizeof(memo));
        vector<vector<int>> jobs(n, vector<int>(3,0));
        for(int i=0; i<n; i++) {
            jobs[i][0] = st[i];
            jobs[i][1] = et[i];
            jobs[i][2] = pft[i];
        }
        sort(jobs.begin(), jobs.end());
        return solve(0, jobs);
    }
};