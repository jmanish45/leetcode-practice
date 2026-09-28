class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int mid = 0;
        int hi = nums.size()-1;
        while(mid<=hi){
            if (nums[mid]==2) {
                nums[mid] = nums[hi];
                nums[hi] = 2;
                hi--;
            }
            else if(nums[mid]==0) {
                nums[mid] = nums[lo];
                nums[lo] = 0;
                lo++;
                mid++;
            }
            else mid++;
    }
    }
};