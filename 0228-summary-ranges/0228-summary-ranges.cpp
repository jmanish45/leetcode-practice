class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n==0) return ans;
        int start = nums[0];
        for(int i = 1; i<n ; i++ ) {
            if(nums[i]!=nums[i-1]+1) {
                if(start!=nums[i-1] ){
                    ans.push_back(to_string(start)+"->"+to_string(nums[i-1]));
                }
                else {
                    ans.push_back(to_string(start));
                }
                start = nums[i];
            }
        }
        //last range to print
        if(start==nums[nums.size()-1]){
            ans.push_back(to_string(start));
        }
        else {
            ans.push_back(to_string(start)+"->"+to_string(nums[n-1]));

        }
        return ans;
    }
};