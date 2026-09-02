class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int odd = 0;
        int midx = -1;
        int minodd = INT_MAX;
        for(int i=0; i<n; i++) {
            if(nums[i]%2!=0) {   //odd
                if(nums[i]<minodd) {
                    minodd = nums[i];
                    midx = i;
                }
                odd++;
            }
        }
        if(odd==0 || odd==n) return true;
        for(int i=0; i<n; i++) {
            if(nums[i]%2==0) {
                if(nums[i]-nums[midx]<1) return false;
            }
        }
        return true;
    }
};