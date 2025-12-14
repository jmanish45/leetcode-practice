// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n,0);
//         int idx = 0;
//         int m = 0;
//         while(m<n) {
//             if(nums[m]%2==0) {
//                 ans[idx] = nums[m];
//                 idx++;
//             } 
//             m++;
//         }
//         m = 0;
//         while(m<n) {
//             if(nums[m]%2!=0) {
//                 ans[idx] = nums[m];
//                 idx++;
//             }
//             m++;
//         }
//         return  ans;
//     }
// };

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j=0; j<n ; j++) {
            if(nums[j]%2==0){
                swap(nums[j],nums[i]);
                i++;
            }
             
        }
        return nums;
    }
};