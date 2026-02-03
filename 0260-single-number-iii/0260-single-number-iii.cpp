class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);

        int xorval  = 0;
        for(int i=0; i<n; i++) {
            xorval = xorval^nums[i];
        }
        cout<<xorval;
        int k = 0;
        for(int i=0; i<=31; i++) {
            if(xorval & (1<<i)) {
                k = i;
                break;
            }
        }
        int gpA = 0;
        int gpB = 0;
        for(auto& num : nums) {
            if(num & (1<<k)) gpA = gpA^num;
            else gpB = gpB^num;
        }

        ans[0]=gpA;
        ans[1] = gpB;

        return ans;
        

    }
};