//First method : Timecompl = O(n) and Space Comp : O(n)  where n lies from k to n, k is unique elements in nums 

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int>mpp;
//         for(int i = 0; i<n; i++) {
//             mpp[nums[i]]++;
//             if(mpp[nums[i]]>n/2) return nums[i];
//         }
//     return -1;
//     }
// };

//Seconf is the most optimal Approach with T.C : O(n) but with Space complexity : O(1) with using Boyer-Moore Voting Algorithm.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = 0;
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(count==0) {
                majority  = nums[i];
                count++;
            }
            else if(nums[i]==majority) {
                count++;
            }
            else count--;

        }
        return majority;
    }
};
