class Solution {
public:
    bool check(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            return true;
        }
        return false;
    }
    int index(char c) {
        if(c=='a') return 0;
        else if(c=='e') return 1;
        else if(c=='i') return 2;
        else if(c=='o') return 3;
        else return 4;
    }
    int countVowelSubstrings(string word) {
        int n = word.length();
        int count = 0;
        for(int i=0 ;i<n; i++) {
            vector<int> v(5,0);
            for(int j=i; j<n; j++) {
                char c = word[j];
                if(check(c)) {
                    int idx = index(c);
                    v[idx]++;
                    if(v[0]!=0 && v[1]!=0 && v[2]!=0 && v[3]!=0 && v[4]!=0) {
                        count++;
                    }
                }
                else break;
            }
        }
        return count;
    }
};