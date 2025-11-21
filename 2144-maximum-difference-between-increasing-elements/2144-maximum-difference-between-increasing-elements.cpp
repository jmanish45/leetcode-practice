class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        int minele = nums[0];
        for(int i = 1; i<n ;i++ ) {
            int diff = nums[i]-minele;
            if(maxi<diff) {
                maxi = diff;
            }
            else if(minele>nums[i] ) {
                minele = nums[i];
            }
        }
        if(maxi==0) return -1;
        return maxi;
    }
};