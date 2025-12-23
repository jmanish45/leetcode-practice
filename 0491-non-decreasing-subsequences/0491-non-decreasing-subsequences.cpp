class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>&  ans, vector<int>& subseq, int idx) {
        if(subseq.size()>=2) {
            ans.push_back(subseq);
        }
        unordered_set<int> st;

        for(int i=idx; i<nums.size(); i++) {
            if((subseq.size()==0 || subseq.back()<=nums[i]) && (st.find(nums[i])==st.end())) {
                subseq.push_back(nums[i]);
                solve(nums, ans, subseq,  i+1);
                subseq.pop_back();
                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>  ans;
        vector<int> subseq;
        solve(nums, ans, subseq, 0);
        return ans;
    }
};
//29,26, 29, 25, 27
//18, 