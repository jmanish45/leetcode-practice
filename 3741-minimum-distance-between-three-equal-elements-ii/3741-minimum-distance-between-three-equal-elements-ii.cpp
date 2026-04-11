class Solution {
public:
    int solve(vector<int> c) {
        int ans = INT_MAX;
        for(int i=0; i<c.size()-2; i++) {
            ans = min(ans, 2*(c[i+2]-c[i]));
        }
        return ans;
    }
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }
        for(auto m : mp) {
            if(m.second.size()>=3) {
                ans = min(ans, solve(m.second));
            }
        }

    return (ans==INT_MAX) ? -1 : ans;
    }
};