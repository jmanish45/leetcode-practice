class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n<=8) return n;
        n-=8;
        int ans = 8;
        int add = 2;
        while(n>0) {
            if(n>=8) ans+=add*8;
            else ans+=add*n;
            n-=8;
            add++;
        }
        return ans;


    }
};