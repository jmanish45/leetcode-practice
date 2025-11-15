class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breaks = 0;
        for(int i = 1;i<n; i++) {
            if(nums[i-1]>nums[i]) breaks++;
        }
        if(breaks==0) return true;
        else if(breaks==1) {
            if(nums[0]>=nums[n-1]) return true;
        }
        return false;
    }
};