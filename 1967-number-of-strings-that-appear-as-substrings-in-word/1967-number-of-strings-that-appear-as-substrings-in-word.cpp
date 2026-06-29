class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int ans = 0;
        for(auto pattern : patterns) {
            if(word.contains(pattern)) ans++;
        }
        return ans;
    }
};