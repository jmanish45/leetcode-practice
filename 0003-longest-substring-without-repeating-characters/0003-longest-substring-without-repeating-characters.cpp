// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         unordered_map<char, int> m;
//         int maxlen = 0;
//         int start = 0;
//         for(int i = 0; i<n; i++) {
//             while(m[s[i]] ) {
//                 m.erase(s[start]);
//                 start++;
//             }
//             m[s[i]] = i;
//             maxlen = max(i - start + 1 , maxlen) ;
//         }
//         return maxlen;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        int start = 0;
        unordered_map<char, int> mp;
        int l = 0;
        for(int i=0; i<n; i++) {
            char c = s[i];
            while(mp[c]>0) {
                mp[s[l]]--;
                
                
                start = l;
                l++;
            }
            mp[c]++;
            int len = i-l+1;
            maxlen = max(maxlen, len);
        }
        //  maxlen = max(maxlen, n-start+1 );
        return maxlen;
    }
};