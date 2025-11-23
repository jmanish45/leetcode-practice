class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1;i++) {
            if(nums[i]==nums[i+1]) {
                nums[i]=nums[i]*2;
                nums[i+1] = 0;
            }

            
        }
        int i = 0;
        while(i<n-1) {
            int j = i+1;
            if(nums[i]==0) {
                while(j<n-1 && nums[j]==0 ) j++;
                swap(nums[i],nums[j]);
            }
            i++;

        }
        
        
        return nums;
        
    }
};