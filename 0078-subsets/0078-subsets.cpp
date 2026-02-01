// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         int totsubsets = 1<<n;
//         vector<vector<int>> ans;
//         /*like there will be 8 subsets so from 0 to 7
//         1) 0 0 0
//         2) 0 0 1
//         3) 0 1 0
//         4) 0 1 1
//         5) 1 0 0
//         6) 1 0 1
//         7) 1 1 0
//         8) 1 1 1 
//         */
//         for(int i = 0; i<totsubsets; i++) {
//             vector<int> subset;
//             for(int j=0; j<n; j++) {
//                 if(i & (1<<j)) {
//                     subset.push_back(nums[j]);
//                 }
//             }
//             ans.push_back(subset);
//         }
//         return ans;
//     }
// };




class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int i) {
        if(i==nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        solve(nums, ans, subset, i+1);
        subset.pop_back();
        solve(nums, ans, subset, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;
        solve(nums, ans, subset, 0);
        return ans;
    }
};
