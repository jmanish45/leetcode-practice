class Solution {
public:
    void getsubsets(vector<int>& nums, vector<vector<int>>& ans,vector<int>& subset, int i ) {
        if(i==nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        getsubsets(nums, ans, subset, i+1);
        subset.pop_back();
        getsubsets(nums, ans, subset, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans; 
        vector<int> subset;
        getsubsets(nums, ans, subset, 0);
        return ans;

    }
};