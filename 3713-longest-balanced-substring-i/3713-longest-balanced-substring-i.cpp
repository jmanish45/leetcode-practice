class Solution {
public:
    bool check(vector<int>& freq) {
        int common = 0;
        for(int i=0; i<26; i++) {
            if(freq[i]==0) continue;
            if(common==0) common = freq[i];
            else if (freq[i]!=common) return false;
        }
        return true;
   }
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0; i<n; i++) {
            vector<int> freq(26, 0);
            for(int j = i; j<n; j++) {
                freq[s[j]-'a']++;
                if(check(freq)) {
                    ans = max(ans, j-i+1);
                }
                
            }
        }
        return ans;
    }
};