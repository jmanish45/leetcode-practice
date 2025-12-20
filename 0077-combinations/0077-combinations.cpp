class Solution {
public:
    void getans(vector<int>& nums, vector<int>& comb,
                vector<vector<int>>& ans, int k, int i) {

        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        if (i == nums.size()) return;
        comb.push_back(nums[i]);
        getans(nums, comb, ans, k, i + 1);

        
        comb.pop_back();


        getans(nums, comb, ans, k, i + 1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }

        vector<int> comb;
        getans(nums, comb, ans, k, 0);
        return ans;
    }
};
