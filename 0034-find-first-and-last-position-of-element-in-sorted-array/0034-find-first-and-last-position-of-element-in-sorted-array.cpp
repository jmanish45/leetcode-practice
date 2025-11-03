class Solution {
public:
    int findbound(vector<int>& nums, int target, int fol) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int ans = -1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target) {
                ans = mid;
                if(fol==0) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }
            }
            else if(nums[mid]<target) lo = mid+1;
            else hi = mid - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        v[0] = findbound(nums, target, 0);
        v[1] = findbound(nums, target, 1);
        return v;
    }    
    
};