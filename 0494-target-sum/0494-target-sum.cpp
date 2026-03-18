// class Solution {
// public:
//     int n;
//     int total;
//     vector<vector<int>> dp;
//     int helper(int i, vector<int> &nums, int sum, int target) {
//         if(i==n) {
//             if(sum == target) return 1;
//             else return 0;
//         }
//         if(dp[i][total+sum]!=-1) return dp[i][total+sum];
//         int add = helper(i+1, nums, sum + nums[i], target);
//         int sub = helper(i+1, nums, sum - nums[i], target);
//         return dp[i][total+sum] =  add + sub; 
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         n = nums.size();
//         total = 0;
//         for(int ele : nums ) {
//             total+=ele;
//         }
//         dp.resize(n, vector<int> (2*total + 1, -1));
//         return helper(0, nums, 0, target);
//     }   
// };

class Solution {
public:
    int ans ;
    void solve(int idx, vector<int>& nums, int sum , int target ) {
        if(idx==nums.size()) {
            if(sum==target) {
                ans++;
            }
            return;
        }

        //taking '+' adding the nums[idx];
        sum+=nums[idx];
        solve(idx+1, nums, sum, target);
        sum-=nums[idx];  //undo changes

        //taking '-' subtracting the nums[i]

        sum-=nums[idx];
        solve(idx+1, nums, sum, target);
        sum+=nums[idx];  //undo changes 

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        solve(0, nums, 0, target);

        return ans; 
    }   
};
