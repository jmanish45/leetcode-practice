// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n =nums.size();
//         int p = 1;
//         int i = 0; 
//         int j = 0;
//         int count= 0;
//         while(j<n) {
//             if(p*nums[i]<k) {
//                 count++;
                
//                 p=p*nums[i];
//                 i++;
//             }
//             else {
//                 i = j + 1;
//                 j++;
//                 p = 1;
//             }
//             if(i==n) {
//                 i = j+1;
//                 j++;
//                 p = 1;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        int p = 1; 
        int count =  0;
        for(int i = 0; i< n; i++) {
            p*=nums[i];
            while(p>=k && j<=i ) {
                p/=nums[j];
                j++;
            }

            count += (i - j + 1);
        }
        return count;
    }
};
