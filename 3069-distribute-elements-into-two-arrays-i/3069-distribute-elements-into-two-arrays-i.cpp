class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1(1, nums[0]);
        vector<int> arr2(1, nums[1]);
        int i = 0 , j = 0;
        for(int k=2; k<n; k++) {
            if(arr1[i]>arr2[j]) {
                arr1.push_back(nums[k]);
                i++;
            }
            else {
                arr2.push_back(nums[k]);
                j++;
            }
        }
        for(int l = 0; l<arr2.size(); l++) {
            arr1.push_back(arr2[l]);
        }
        return arr1;

    }
};