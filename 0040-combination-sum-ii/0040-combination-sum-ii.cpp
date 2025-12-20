class Solution {
public:
    set<vector<int>> st;
    void back(vector<int>& nums, vector<vector<int>>& ans, vector<int>& comb, int target, int i) {
        if(target==0) {
            
            if(st.find(comb)==st.end()) {
                ans.push_back(comb);
                st.insert(comb);
            }
            
            return;
        }
        if(target<0 || i==nums.size()) return;
        comb.push_back(nums[i]);
        back(nums, ans, comb, target-nums[i], i+1);
        comb.pop_back();
        int j = i+1;
        while (j  < nums.size() && nums[j] == nums[j-1]) {
            j++;
        }
        back(nums,ans, comb, target, j);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> comb;
        back(nums, ans, comb, target, 0);
        return ans;

    }
};