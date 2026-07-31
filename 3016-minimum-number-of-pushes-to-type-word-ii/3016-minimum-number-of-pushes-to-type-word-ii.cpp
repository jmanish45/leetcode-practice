class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};

        
        for(char c : word) {
            freq[c - 'a']++;
        }
        sort(freq, freq + 26, greater<int>());
        int ans = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0)
                break;

            int pushes = i / 8 + 1;

            ans += freq[i] * pushes;
        }
        return ans;
    }
};