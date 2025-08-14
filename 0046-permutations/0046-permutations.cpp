class Solution {
public:
    vector<int> nextpermutation(vector<int> & nums) {
        int n = nums.size();
        int piv = -1;
        for(int i = n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                piv = i;
                break;
            }
        }
        if(piv==-1) {
             reverse(nums.begin(), nums.end());
             return nums;
        }
        
        
        reverse(nums.begin()+piv+1, nums.end());
       
        int j = -1;
        for(int i = piv+1 ;i<n;i++) {
            if(nums[piv]<nums[i]) {
                j = i;
                break;
            }
        }
        
        int temp = nums[piv];
        nums[piv] = nums[j];
        nums[j] = temp;
        return nums;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> start = nums;
        ans.push_back(start);
        
        vector<int> np = nextpermutation(nums);
        
        while(np!=start) {
            ans.push_back(np);
            np = nextpermutation(np);
            
        }
        
        return ans;
    }
};