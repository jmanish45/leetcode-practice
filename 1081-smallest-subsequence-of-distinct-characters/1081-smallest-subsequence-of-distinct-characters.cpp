class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        string ans = "";
        vector<int> lastidx(26,-1) ;
        for(int i = 0; i<n; i++) {
            lastidx[s[i]-'a'] = i;
        }
        vector<bool> taken(26,false);
        for(int i = 0; i<n ;i++) {
            if(taken[s[i]-'a']==true) continue;

            while(ans.length()>0 && ans.back()>s[i] && lastidx[ans.back()-'a'] > i) {
                taken[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);    
            taken[s[i]-'a'] = true;
        }

        return ans;
    }
};