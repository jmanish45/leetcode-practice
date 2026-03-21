class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int count = 0;
        unordered_map<int, int> freq;

        for(int j = 0; j<n ; j++) {
            freq[nums[j]]++;

            while(freq.size() > k) {
                freq[nums[i]]--;
                if(freq[nums[i]]==0) freq.erase(nums[i]);
                i++;
            }
            count = count + (j-i+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k ) - solve(nums, k-1);
    }
};