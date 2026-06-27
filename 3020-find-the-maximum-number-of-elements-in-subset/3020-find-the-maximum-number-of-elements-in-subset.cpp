class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;
        map<ll,int> mp;
        int ones = 0;
        for(auto num : nums) {
            if(num==1) ones++;
            else mp[num]++;
        }
        if(ones!=0 && ones%2==0) ones--;
        int ans = ones;
        for(auto it : mp) {
            ll val = it.first;
            ll root = sqrt(val);
            if(root*root==val && mp[root]>1) {
                continue;
            }
            int count = 0 ;
            while(mp[val]>1) {
                count+=2;
                val = val*1ll*val;
            }
            if(mp[val]==1) count++;
            else count--;
            ans = max(ans, count);
        }
        return ans;
    }
};