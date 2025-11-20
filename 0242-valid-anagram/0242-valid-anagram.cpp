class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m!=n) return false;
        vector<int> v(26,0);
        for(int i = 0;i<n; i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<n;i++) {
            char c = t[i];
            if(v[c-'a']==0) return false;
            else {
                v[c-'a']--;
            }
        }
        return true;
    }
};