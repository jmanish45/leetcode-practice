class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long mult = 1;
        long long sum  = 0;
        while(n>0) {
            int ld = n%10;
            n/=10;
            if(ld==0) {
                continue;
            }
            x += ld*mult;
            mult*=10;
            sum+=ld;
            
        }
        return x*sum;
    }
};