class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cntlow = 0;
        int equal = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==target) equal++;
            else if(nums[i]<target) cntlow++;
        }
        vector<int> ans;
        for(int i=0; i<equal; i++) {
            ans.push_back(cntlow++);
        }
        return ans;
    }
};