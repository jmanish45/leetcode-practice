class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0; i<n; i++) {
            sum+=nums[i];
            int rem = sum - k;
            if(mp.find(rem)!=mp.end()) {
                count+=mp[rem];
            }
            mp[sum]++;
        }
        return count;
    }
};

//Second Approach
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> prefix(n);
//         prefix[0] = nums[0];
//         for(int i = 1; i<n ;i++) {
//             prefix[i] = nums[i] + prefix[i-1];
//         }
//         int count = 0 ;
//         int j = 0;
//         for(int i = 0; i < n; i++) {
//             if(prefix[i]==k) {
//                 count++;
//             }
            
//             for(int j = 0; j<i ;j++) {
//                 if(prefix[i] - prefix[j] == k) {
//                     count++;
//                 }
//             }
            
//         }
//         return count;
        
//     }
// };