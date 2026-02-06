class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  //1,2,5
        int n = nums.size();  //n=3
        int j = 0;  
        int maxlen = 0;  
        for(int i=0; i<n; i++) {
            while(nums[i] >(long long)nums[j]*k) {
                j++;
            }
            maxlen = max(maxlen, i-j+1);
        }
        return n-maxlen;
    }
};