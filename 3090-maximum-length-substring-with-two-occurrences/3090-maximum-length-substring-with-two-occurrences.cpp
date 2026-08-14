class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int l = 0 , r = 0;
        int len = 0;
        int maxlen = 0;
        while(r<n) {
            while(mp.find(s[r])!=mp.end() && mp[s[r]]==2) {
                mp[s[l]]--;
                if(mp[s[r]]==0 ) {
                    mp.erase(s[r]);
                }
                l++;
            }
            mp[s[r]]++;
            len = r-l+1;
            maxlen = max(maxlen, len);
            r++;
        }

        return maxlen ;
    }
};