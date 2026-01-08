class Solution {
public:
    int n1, n2 ;
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i==n1 || j==n2) return -1e9;
        if(dp[i][j]!=-1e9) return dp[i][j];

        int prod = nums1[i]*nums2[j];
        int keep_i = solve(nums1, nums2, i, j+1);
        int keep_j = solve(nums1, nums2, i+1, j);
        int keep_i_j = prod + solve(nums1, nums2, i+1, j+1);

        return dp[i][j] =  max(prod, max(keep_i, max(keep_j, keep_i_j)));

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();
        for(int i = 0;i<501; i++) {
            for(int j=0; j<501; j++) {
                dp[i][j] = -1e9;
            }
        }
        int ans = solve(nums1, nums2, 0, 0);
        return ans;
    }
};