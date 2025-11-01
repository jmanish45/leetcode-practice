class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 01; i<n ;i++) {
            prefix[i] = prefix[i-1]+nums[i];
        }
        int count = 0;
        for(int i= 0; i<n; i++) {
            if(prefix[i]==k) count++;
            for(int j=0; j<i ;j++){
                if(prefix[i]-prefix[j] == k) count++;
            }
        }
        return count;
    }
};