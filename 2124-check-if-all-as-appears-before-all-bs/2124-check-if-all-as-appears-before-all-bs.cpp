class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int la = 0;
        int fb = n-1;
        for(int i=0; i<n; i++) {
            if(s[i]=='b') {
                fb = min(fb, i);
            }
            else if(s[i]=='a') {
                la = max(la, i);
            }
        }
        if(la>fb) return false;
        else return true;    
    }
};