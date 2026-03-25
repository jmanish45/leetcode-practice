class Solution {
public:
    bool check(vector<int>& freq) {
        for(int i=0; i<26; i++) {
            if(freq[i]!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();
        vector<int> ans; 
        vector<int> freq(26,0);
        for(int i=0; i<k; i++) {
            freq[p[i]-'a']++;
        }
        
        int i = 0, j = 0;
        while(j<n) {
            char c = s[j];
            
            freq[c-'a']--;
            
            if(j-i+1==k) {
                if(check(freq)) {
                    ans.push_back(i);
                }
                freq[s[i]-'a']++;
                i++;
            }
            j++;

        }
        return ans;
    }
};