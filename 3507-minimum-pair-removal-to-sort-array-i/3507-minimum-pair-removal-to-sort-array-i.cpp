class Solution {
public:
    vector<int> stimulate(vector<int>& nums) {
        int n = nums.size();
        vector<int> change(n-1);
        int minidx = 0;
        int minsum = INT_MAX;
        for(int i=1; i<n; i++) {
            int sum = nums[i]+nums[i-1];
            if(sum<minsum) {
                minsum = sum;
                minidx = i;
            }    
        }
        int j=0;
        for(int i=0; i<n; i++) {
            if(i==minidx-1) {
                change[j]=minsum;
                j++;
            }
            else if(i==minidx) {
                continue;
            }
            else {
                change[j] = nums[i];
                j++;
            }

        }

        return change;

        


    }
    bool isSorted(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int oprn = 0;
        while(!isSorted(nums)) {
            oprn++;
            nums = stimulate(nums);
        }

        return oprn;
    }
};