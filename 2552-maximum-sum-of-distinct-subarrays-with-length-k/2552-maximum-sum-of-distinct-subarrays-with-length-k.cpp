class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = k-1;
        long long maxsum = 0;
        long long sum = 0;
        unordered_map<int, int> freq;
        for(int s = 0; s<k ;s++) {
            sum+=nums[s];
            freq[nums[s]]++;
        }
        if(freq.size()==k) maxsum = sum;
        
        while(j<n) {
            sum-=nums[i];
            freq[nums[i]]--;
            if(freq[nums[i]]==0) freq.erase(nums[i]);
            i++;
            j++;
            if(j==n) break;
            sum+=nums[j];
            freq[nums[j]]++;
            if(freq.size()==k) maxsum = max(sum, maxsum);
        }
        return maxsum;

    }
};