class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        //given : nums
        //threshold : limit
        //starting at l and ending at r
        //nums[l] is even
        //even , odd, even , odd
        //for l<=i<=r nums[i]<=threshold
        int start = 0;
        int r = 0;
        int n = nums.size();
        int maxlen = 0;
        int count = 0;
        while(r<n) {
            if(nums[r]%2==0 && count==0 && nums[r]<=threshold) {
                start = r;
                count = 1;
                maxlen = max(maxlen, r-start+1);
            }
            else if(r>0 && (nums[r]%2 != nums[r-1]%2)  && count>0 && nums[r]<=threshold) {
                maxlen = max(maxlen, r-start+1);
                count = 1;
            }

            else {
                count = 0;
                if (nums[r] % 2 == 0 && nums[r] <= threshold) {
                    start = r;
                    count = 1;
                    maxlen = max(maxlen, 1);
                }

            }
            r++;
        }
        return maxlen;

    }
};