class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> m;
        int maxlen = 0;
        int start = 0;
        for(int i = 0; i<n; i++) {
            while(m[s[i]]>0 ) {
                m.erase(s[start]);
                start++;
            }
            m[s[i]]++;
            maxlen = max(i - start + 1 , maxlen) ;
        }
        return maxlen;
    }
};