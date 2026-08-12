class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;

        stack<int> st;
        int n = nums2.size();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top()<=nums2[i]) {
                st.pop();
            }
            nge[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int num : nums1 ) {
            ans.push_back(nge[num]);
        }
        return ans;
    }
};