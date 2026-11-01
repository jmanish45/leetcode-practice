
class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> dp;
    vector<vector<bool>> visited;

    // {length, count}
    pair<int,int> solve(int prev, int curr, vector<int>& nums) {

        if(curr == n) return {0, 1};

        int p = prev + 1;

        if(visited[p][curr])
            return dp[p][curr];

        visited[p][curr] = true;

        pair<int,int> take = {-1, 0};

        if(prev == -1 || nums[prev] < nums[curr]) {
            take = solve(curr, curr + 1, nums);
            take.first++;
        }

        pair<int,int> skip = solve(prev, curr + 1, nums);

        if(take.first > skip.first)
            return dp[p][curr] = take;

        if(skip.first > take.first)
            return dp[p][curr] = skip;

        return dp[p][curr] = {
            take.first,
            take.second + skip.second
        };
    }

    int findNumberOfLIS(vector<int>& nums) {
        n = nums.size();

        dp.resize(n + 1,
            vector<pair<int,int>>(n, {0, 0}));

        visited.resize(n + 1,
            vector<bool>(n, false));

        return solve(-1, 0, nums).second;
    }
};
