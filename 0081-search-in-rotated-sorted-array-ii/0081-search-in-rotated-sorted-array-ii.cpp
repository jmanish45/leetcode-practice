class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return 1;
            //checking duplicates if they are occuring thus not letting to decide that  which side should betrimmed or can be ignored, so we trim the ranges from both lo and hi side by one so that we dont conflict with  the dupliactes 
            if(nums[mid]==nums[lo] && nums[mid]==nums[hi]) {
                lo=lo+1;
                hi=hi-1;
                continue;   // continue meas again starting the process from first
                
            }

            //left sorted array 
            if(nums[mid]>=nums[lo]) {
                if(nums[lo]<=target && nums[mid]>=target) {
                    hi=mid-1;
                }
                else lo = mid+1;
            }
            else if(nums[mid]<=nums[hi]) {
                if(nums[mid]<=target && nums[hi]>=target) {
                    lo=mid+1;
                }
                else {
                    hi=mid-1;
                }
            }
        }
        return 0;
    }
};