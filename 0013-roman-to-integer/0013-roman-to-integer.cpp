class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int num = 0;
        int n = s.length();
        for(int i = 0; i<n; i++) {
            char c = s[i];
            if(i<n-1) {
                char t = s[i+1];
                if(mp[c]<mp[t]) num-=mp[c];
                else num+=mp[c];
            }
            else num+=mp[c];
        }
        return num;
    }
};