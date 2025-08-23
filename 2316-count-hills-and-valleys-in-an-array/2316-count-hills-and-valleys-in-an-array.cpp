class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i = 0;
        int count = 0;
        int n = nums.size();
        for(int j = 1; j<n-1; j++) {
            if(nums[j]!=nums[j+1]) {
                if(nums[i]<nums[j] && nums[j]>nums[j+1] || nums[i]>nums[j] && nums[j]<nums[j+1]) count++;
            
            i = j;
            }
        }
        return count;
    }
};