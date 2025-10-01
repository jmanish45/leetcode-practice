class Solution {
public:
    bool canConstruct(string ran, string mag) {
        int r = ran.length();
        int m = mag.length();
        if(r>m) return false;
        unordered_map<char, int> ch;
        for(int i = 0 ; i<r; i++) {
            ch[ran[i]]++;
        }
        for(int i= 0; i<m; i++) {
            if(ch.find(mag[i])!=ch.end()) {
                ch[mag[i]]--;
            }
            if(ch[mag[i]]==0) ch.erase(mag[i]);
        }
        return ch.empty();
    }
};