class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo= 0;
        int hi = n-1;
        //the sorted array rotated is always thorugh only one point so at any point in the array or from any index the array will be sorted completely in the left part or right part and from both sides if look from the pivot point at which the roation is done 
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            //if not found then checkin left sorted array
            //left sorted array
            if(nums[lo]<=nums[mid]) {
                if(nums[lo]<=target && nums[mid]>=target) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;

                }
            }

            //right sorted array
            else if(nums[mid]<=nums[hi]) {
                if(nums[mid]<=target && nums[hi]>=target) {
                    lo =mid+1;
                }
                else {
                    hi = mid-1;
                }
             }


        }
        return -1;
    }
};