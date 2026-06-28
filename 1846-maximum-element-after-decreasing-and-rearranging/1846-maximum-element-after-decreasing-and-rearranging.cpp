class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]!=1) nums[0] = 1;
        int maxi = 1;
        for(int i = 1; i<n; i++) {
            if(abs(nums[i]-nums[i-1])>1) nums[i] = nums[i-1]+1;
            if(maxi<nums[i]) maxi = nums[i];
        }
        return maxi;
    }
};