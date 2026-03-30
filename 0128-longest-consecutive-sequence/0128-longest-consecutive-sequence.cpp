class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;
        int maxl = 1;
        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }
        for(auto& ele : st) {
            int count = 1;
            int x = ele;
            if(st.find(x-1)!=st.end()) continue;
            while(st.find(x+1)!=st.end()) {
                count++;
                x++;
            }
            maxl = max(maxl,count);
        
        }
        return maxl;
    }
};
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(n==0) return 0;
//         sort(nums.begin(), nums.end());
//         int longest = 0;
//         int count = 0;
//         int lastsmallest = INT_MIN;
//         for(int i = 0 ; i<n ; i++) {
//             if(nums[i]-1 == lastsmallest) {
//                 count+=1;
//                 lastsmallest = nums[i];
//             }
//             else if(lastsmallest != nums[i]) {
//                 count = 1;
//                 lastsmallest = nums[i];
//             }
//             longest = max(count, longest);
//         }
//         return longest;
//     }
// };