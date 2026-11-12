class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int currl=1;
        int maxl = 1;
        for(int i =0; i< n-1; i++) {
            if(nums[i]<nums[i+1] ) {
                currl++;
                maxl = max(maxl, currl);
            }
            else {
                currl = 1;
            }
        }
        currl=1;
        cout<<"ml:"<<maxl<<"curr : "<<currl<<endl;
        for(int i = 0; i<n-1; i++) {
            if(nums[i]>nums[i+1]) {
                currl++;
                if(maxl < currl) maxl = currl;
                //else maxlength = currlength;
                cout<<"i = "<<i<<" ml: "<<maxl<<endl;;
            }
            else {
                currl = 1;
            }
        }
        
        return maxl;
    }
};