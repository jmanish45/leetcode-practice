class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int maxfreq = 0;
        
        unordered_map<char, int> mp;
        while(r<n) {
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);
            int len =  r - l + 1;
            int flips = (len - maxfreq);
            if(flips>k) {
                mp[s[l]]--;
                maxfreq = 0;
                for(auto &ele : mp) {
                    maxfreq = max(maxfreq, ele.second);
                }
                l++;
            }
            
            maxlen = max(maxlen, r-l+1);
            
            r++;
        }
        return maxlen;
    }
};