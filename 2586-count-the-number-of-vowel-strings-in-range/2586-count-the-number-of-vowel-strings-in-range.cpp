class Solution {
public:
    bool isvowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            return true;
        }
        return false;
    }
    bool check(string& word) {
        int n = word.length();
        if(isvowel(word[0]) && isvowel(word[n-1])) {
            return true;
        }
        else return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        
        int count = 0;
        for(int i=left; i<=right; i++)  {
            if(check(words[i])) count++;
        }

        return count;
    }
};