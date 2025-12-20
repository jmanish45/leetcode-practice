class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& ans, vector<int>& comb, int target , int idx) {
        
        if(target==0) {
            ans.push_back(comb);
            return;
        }
        if(target<0 || idx==nums.size()) return ;
        comb.push_back(nums[idx]);
        backtrack(nums, ans,  comb ,target-nums[idx], idx);
        comb.pop_back();
        backtrack(nums,  ans, comb, target, idx+1);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(nums, ans, comb , target , 0);
        return ans;
    }
};