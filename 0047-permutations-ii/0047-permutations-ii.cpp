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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set <vector<int>> st;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> start = nums;
        st.insert(start);
        vector<int> np = nextpermutation(nums);
        while(np!=start) {
            st.insert(np);
            np = nextpermutation(np);
            
        }
        for(auto ele : st)  {
            ans.push_back(ele);
        }
        return ans;
    }
};