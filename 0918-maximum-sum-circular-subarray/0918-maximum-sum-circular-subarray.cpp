class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //instead of calcu;ating the maxsub array sum in circular array just
        //calculate the minimum sub array sum 
        int currsum = 0;
        int currmax = 0;
        int maxsum = INT_MIN;
        int minsum = INT_MAX;
        int totsum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            currsum = min(currsum+nums[i],nums[i]);
            minsum = min(currsum, minsum);
            currmax = max(currmax+nums[i],nums[i]);
            maxsum = max(maxsum, currmax);
            totsum += nums[i];
        }
        if(totsum==minsum) return maxsum;
        return max(maxsum,totsum - minsum);
    }
};