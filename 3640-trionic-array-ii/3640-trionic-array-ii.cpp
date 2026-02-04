// class Solution {
// public:
//     bool isTrionic( vector<int>& nums) {
//         int n = nums.size();
//         int i = 0;
//         while(i+1<n && nums[i]<nums[i+1]) i++;
//         if(i==0 || i+1 == n) return false;
//         int p = i;
//         while(i+1<n && nums[i]>nums[i+1]) i++;
//         if(i==p || i+1 == n ) return false;
//         int q = i;
//         while(i+1<n && nums[i]<nums[i+1]) i++;
//         if(i==q || i!=n-1) return false;
//         return true;
//     }
//     long long maxSumTrionic(vector<int>& nums) {
//         //min of 4 size slidng window is required for  each subarray to Be trionic 
//         long long maxsum = LLONG_MIN;
//         int n = nums.size();
//         for(int l = 0; l <= n-4; l++) {
//             for(int r = l + 3; r<n ; r++) {
//                 vector<int> sub(nums.begin()+l , nums.begin()+r+1);
//                 if(isTrionic(sub)) {
//                     long long sum = accumulate(sub.begin(), sub.end(), 0LL);
//                     maxsum = max(maxsum, sum);
//                 }
//             }
//         }
//         return maxsum;
        
//     }
// };
class Solution {
public:
   long long maxSumTrionic(vector<int>& nums) {
    long long n = nums.size(), res = LLONG_MIN, psum = nums[0];
    for (int l = 0, p = 0, q = 0, r = 1; r < nums.size(); ++r) {
        psum += nums[r];
        if (nums[r - 1] == nums[r]) {
            l = r;
            psum = nums[r];
        }
        else if (nums[r - 1] > nums[r]) {
            if (r > 1 && nums[r - 2] < nums[r - 1]) { // flip
                p = r - 1;
                while (l < q)
                    psum -= nums[l++];    
                while (l + 1 < p && nums[l] < 0)
                    psum -= nums[l++];
            }
        }
        else {
            if (r > 1 && nums[r - 2] > nums[r - 1]) // flip
                q = r - 1;
            if (l < p && p < q)
                res = max(res, psum);
        }
    }
    return res;
}
};
