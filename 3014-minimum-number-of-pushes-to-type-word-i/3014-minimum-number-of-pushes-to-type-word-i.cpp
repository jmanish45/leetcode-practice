// class Solution {
// public:
//     int minimumPushes(string word) {
//         int n = word.length();
//         if(n<=8) return n;
//         n-=8;
//         int ans = 8;
//         int add = 2;
//         while(n>0) {
//             if(n>=8) ans+=add*8;
//             else ans+=add*n;
//             n-=8;
//             add++;
//         }
//         return ans;


//     }
// };

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0 ;
        for(int i=0; i<n; i++) {
            ans+=(i/8)+1;
        }
        return ans;
    }
};