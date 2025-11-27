class Solution {
public:
    bool isvalid(vector<int>& nums, long long maxarr ) {
        vector<long long> arr(begin(nums), end(nums));
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            if(arr[i]>maxarr) return false;
            long long buffer = maxarr - arr[i];
            arr[i+1] = arr[i+1]-buffer;

        }
        if(arr[n-1]>maxarr) return false;
        else return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        //[3,7,1,6]
        //index from 1 to n;
        //nums[i]-- and nums[i-1]++
        int maxi = nums[0];
        
        for(int i=1; i<n; i++) {
            maxi = max(nums[i],maxi );
            
        }
        int lo = 1;
        int hi = maxi;
        int ans = 0;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(isvalid(nums, mid)) {
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return ans;

    }
};