class Solution {
public:
    void getsubsets(vector<int>& nums, vector<vector<int>>& ans,vector<int>&
     subset, int i ) {
        if(i==nums.size()) {
            ans.push_back(subset) ;
            return;
        }
        subset.push_back(nums[i]);
        getsubsets(nums, ans, subset, i+1);
        subset.pop_back();

        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) {
            idx++;
        } 
        getsubsets(nums, ans, subset, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        getsubsets(nums, ans, subset, 0);
        return ans;
    }
};