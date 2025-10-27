class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n =  nums.size();
        
        int  finalans = 0;
        int mindiff = INT_MAX;
        sort(nums.begin(),  nums.end());
        for(int i=0; i<n; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
        
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < mindiff) {
                    mindiff = abs(target-sum);
                    finalans = sum;
                    
                }

                if(sum<target) {
                    j++;
                }
                else if(sum>target) {
                    k--;
                }
                else {
                
                    return  sum;
                }
            
            }
            
        }
        
        return finalans;
    }
};