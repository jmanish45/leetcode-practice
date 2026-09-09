class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.length();
        vector<int> mp(26,-1);
        for(int i=0; i<n; i++) {
            mp[s[i]-'a'] = i;
        }
        int i = 0;
        int start = 0;
        int end = 0;
        while(i<n) {
            end = max(mp[s[i]-'a'], end);
            if(i==end) {
                ans.push_back(end-start+1);
                start = end+1;
            }
            i++;
        }
        return ans;
    }
};