class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        if (n == 0 || m == 0) return {};
        int w = words[0].size();
        int t = m * w;
        unordered_map<string, int> mp;
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            mp[words[i]]++;
        }

        // Try all possible offsets
        for (int offset = 0; offset < w; offset++) {
            int left = offset, right = offset, count = 0;
            unordered_map<string, int> window;
            while (right + w <= n) {
                string word = s.substr(right, w);
                right += w;
                if (mp.count(word)) {
                    window[word]++;
                    count++;
                    // If word occurs more than needed, move left pointer
                    while (window[word] > mp[word]) {
                        string leftWord = s.substr(left, w);
                        window[leftWord]--;
                        count--;
                        left += w;
                    }
                    // If all words matched
                    if (count == m) {
                        ans.push_back(left);
                        // Move left to search for new window
                        string leftWord = s.substr(left, w);
                        window[leftWord]--;
                        count--;
                        left += w;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         int n = s.size();
//         int m = words.size();
//         int w = words[0].size();
//         int t = m*w;
//         unordered_map<string, int> mp;
//         vector<int> ans;
//         for(int i = 0;i<m; i++){
//             mp[words[i]]++;
//         }
//         int  count = 0;
//         for(int i = 0; i<=n-t; i++) {
//             unordered_map<string, int> mpp = mp;
//             int j = i;
//             count=0;
//             while(j<t+i) {
                 
//                 string sub = s.substr(j,w);
                
//                 if(mpp[sub]>0) {
//                     mpp[sub]--;
//                     count++;
//                     if(mpp[sub]==0) mpp.erase(sub);
//                 }
//                 else {
//                    break; 
//                 }
                
//                 j+=w;
//             }
//             if(count==m) ans.push_back(i);
//         }
//         return ans;

//     }
// };