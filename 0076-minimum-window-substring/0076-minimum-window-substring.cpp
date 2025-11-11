class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(n>m) return "";

        unordered_map<char, int> need;
        for(char c : t) {
            need[c]++;
        }
        int req = need.size();
        int i = 0;
        int got = 0;
        int minlen = m+1;
        int start = 0;
        unordered_map<char, int> window;
        for(int j=0; j<m ;j++) {
            char c = s[j];
            window[c]++;
            if(need.find(c)!=need.end() &&  window[c]==need[c]) {
                got++;
            }
            while(got==req) {
                if(minlen > j-i+1) {
                    minlen = j-i+1;
                    start = i;
                }    
                char l = s[i];
                window[l]--;
                if((need.find(l)!=need.end()) && need[l]>window[l]) {
                    got--;
                }  
                
                

                i++;

            }
            
            
            
        }
        if(minlen==m+1) return "";
        return  s.substr(start, minlen);

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
