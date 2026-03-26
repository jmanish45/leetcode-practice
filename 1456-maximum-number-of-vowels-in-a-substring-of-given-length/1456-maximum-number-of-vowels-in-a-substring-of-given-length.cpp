class Solution {
public:
    bool isVowel(char c ) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i<k; i++) {
            char c = s[i];
            if(isVowel(c)) {
                count++;
            }
        }
        int maxcount = count ;
        for(int i = k; i<n; i++) {
            char f = s[i-k];
            if(isVowel(f)) count--;
            char l = s[i];
            if(isVowel(l)) count++;
            maxcount = max(count, maxcount);
        }
        return maxcount ;
    }
};