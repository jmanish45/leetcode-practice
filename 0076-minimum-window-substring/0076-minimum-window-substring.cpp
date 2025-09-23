class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (n > m) return "";

        unordered_map<char, int> need;   // frequency of chars in t
        for (char c : t) need[c]++;

        unordered_map<char, int> window; // frequency of chars in current window
        int have = 0, needCount = need.size(); 

        int left = 0;
        int minLen = m + 1;
        int start = 0; // to store best window start index

        for (int right = 0; right < m; right++) {
            char c = s[right];
            window[c]++;

            if (need.find(c) != need.end() && window[c] == need[c]) {
                have++;
            }

            // shrink the window while valid
            while (have == needCount) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // pop from left
                char lChar = s[left];
                window[lChar]--;
                if (need.find(lChar) != need.end() && window[lChar] < need[lChar]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == m + 1 ? "" : s.substr(start, minLen);
    }
};


// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int m = s.length();
//         int n = t.length();
//         int len = m + 1;
//         string ans = "";

//         if (n > m) return ans;

//         unordered_map<char, int> mp;
//         for (char c : t) {
//             mp[c]++;
//         }

//         for (int i = 0; i <= m - n; i++) {
//             unordered_map<char, int> temp = mp; // fresh copy for each i
//             int count = n; // number of chars still needed

//             for (int j = i; j < m; j++) {
//                 if (temp.find(s[j]) != temp.end()) {
//                     if (temp[s[j]] > 0) {
//                         count--;
//                     }
//                     temp[s[j]]--;
//                 }

//                 if (count == 0) { 
//                     int currlen = j - i + 1;
//                     if (currlen < len) {
//                         len = currlen;
//                         ans = s.substr(i, currlen);
//                     }
//                     break; 
//                 }
//             }
//         }
//         return ans;
//     }
// };
