class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freqb(26,0);
        vector<int> freqt(26,0);
        string word = "balloon";
        for(int i=0; i<word.length(); i++) {
            freqb[word[i]-'a']++;
        }
        for(int i=0; i<text.length(); i++) {
            freqt[text[i]-'a']++;
        }
        int mindiv = INT_MAX;
        for(int i = 0; i<26; i++) {
            int div = 0;
            int num = freqt[i];
            int deno = freqb[i];
            if(deno>num) return 0;
            if(deno!=0) div = num / deno;
            
            if(div!=0) mindiv = min(mindiv, div); 
        }
        return mindiv;
    }
};