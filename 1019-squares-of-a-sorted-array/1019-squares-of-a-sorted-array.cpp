class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        int j = n-1;
        int k = n-1;
        while(i<=j) {
            int isq = nums[i]*nums[i];
            int jsq = nums[j]*nums[j];
            if(isq<jsq) {
                ans[k] = jsq;
                j--;
            }
            else if(isq>=jsq){
                ans[k] = isq;
                i++;
            }
            k--;
        }
        return ans;
    }
};