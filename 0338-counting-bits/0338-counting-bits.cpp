// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n+1);
//         for(int i=0; i<=n; i++) {
//             int ones = 0;
//             for(int j=0; j<31; j++) {
//                 if(i & (1<<j)) ones++;
//             }
//             ans[i] = ones;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if(n==0) return ans;
        ans[0] = 0;
        for(int i=1; i<=n; i++) {
            if(i%2==1) ans[i] = ans[i/2]+1;
            else ans[i] = ans[i/2];
        }
        return ans;
    }
};