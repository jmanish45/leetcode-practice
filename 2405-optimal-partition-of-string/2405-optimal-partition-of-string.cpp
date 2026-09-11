class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int count = 1;
        int start = -1 ;
        int i = 0;
        vector<int> mp(26, -1);
        while(i<n) {
            if(mp[s[i]-'a']>start) {
                count++;
                start = i-1;
            }
            mp[s[i]-'a'] = i;
            i++;
        }
        return count;
    }
};