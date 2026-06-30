// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.length();
//         int count = 0 ;
//         for(int i = 0; i<n ;i++) {
//             vector<char> c(3,0);
//             for(int j = i; j<n; j++) {
//                 c[s[j]-'a'] = 1;
//                 if(c[0]+c[1]+c[2] == 3) {
//                     count = count + (n-j);
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastseen(3,-1);
        int count = 0;
        for(int i = 0; i<n; i++) {
            lastseen[s[i]-'a'] = i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1) {
                count = count + 1+ (min(min(lastseen[0], lastseen[1]), lastseen[2]));
            }
        }
        
        return count;
    }
};