class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> parts;
        string a = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' || i == (s.length() - 1)) {
                if (s[i] != ' ') a += s[i];
                parts.push_back(a);
                a = "";
            } else {
                a += s[i];
            }
        }
        if (parts.size() != p.length()) return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> rev;  

        for (int i = 0; i < p.length(); i++) {
            char c = p[i];
            string w = parts[i];

            if (mp.find(c) != mp.end()) {
                if (mp[c] != w) return false;
            } else {
                mp[c] = w;
            }

            if (rev.find(w) != rev.end()) {
                if (rev[w] != c) return false;
            } else {
                rev[w] = c;
            }
        }

        return true;
    }
};
