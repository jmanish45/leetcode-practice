class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = s.length();
        unordered_map<char,int> mp;
        int l = 0;
        int maxlen = 0;
        for(int i=0; i<m; i++) {
            char c = s[i];
            while(mp[c]>0) {
                mp[s[l]]--;
                l++;
            }
            mp[c]++;
            int len = i-l+1;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};