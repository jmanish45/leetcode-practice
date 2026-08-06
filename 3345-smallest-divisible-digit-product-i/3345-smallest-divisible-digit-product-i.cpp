class Solution {
public:
    int product(int n) {
        int p = 1;
        while(n) {
            int ld = n%10;
            p*=ld;
            n=n/10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        while(true) {
            int prod = product(ans);
            if(prod%t==0) return ans;
            ans++;
        }
        return -1;
    }
};