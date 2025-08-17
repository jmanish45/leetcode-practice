class Solution {
public:
    set<vector<int>> st;
    void getper(vector<int> &nums, int idx, vector<vector<int>> &ans) {
       
        if(idx==nums.size()) {
            if(st.find(nums)==st.end()) {
                st.insert(nums);
                ans.push_back(nums);
            }
            
            return;
        }
        
        for(int i = idx;  i<nums.size();  i++) {
            
            swap(nums[idx], nums[i]);
            getper(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        getper(nums, 0, ans);
        return ans;
    }
};