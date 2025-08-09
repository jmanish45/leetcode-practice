class Solution {
public:
    bool solve(int i, int j,  string& s) {
        if(i>=j) {
            return 1;
        }
        if(s[i]==s[j]) return solve(i+1, j-1, s);
        return 0;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i<n; i++) {
            for(int  j = i; j<n; j++) {
                if(solve(i,j, s)==true) {
                    count++;
                }
            }
        }
        return count;
    }
};