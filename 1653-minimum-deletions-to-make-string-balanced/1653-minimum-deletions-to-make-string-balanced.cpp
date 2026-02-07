class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int ans = n;
        vector<int> prevB(n);
        vector<int> nextA(n);
        int b = 0;
        for(int i=0; i<n; i++) {
            prevB[i] = b;
            if(s[i]=='b') b++;
        }
        int a = 0;
        for(int i=n-1; i>=0; i--) {
            nextA[i] = a;
            if(s[i]=='a') a++;
        }

        for(int i = 0; i< n ; i++) {
            ans = min(ans, prevB[i]+nextA[i]) ;
        }
        
        return ans;
    }
};


//s  =  aababbab
//B's = 00011233
//A's = 32211100


//B'S = 012222223
//A's = 554321000

//ans = 11
