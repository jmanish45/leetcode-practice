class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(int i=0; i<n; i++) {
            v[i] = abs(nums[i]);
        }
        sort(v.begin(),v.end());
        int i = 0;
        int j = n-1;
        long long ans = 0;
        while(i<=j) {
            ans+=(v[j]*v[j]);
            if(i!=j) ans-=(v[i]*v[i]);
            i++;
            j--;
        }
        return ans;

    }
};