class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        long long comma = 1;
        while(start<=n) {
            long long next = start*1000;
            long long end = min(n, next-1);
            ans += (end-start+1) * comma;
            start = next;
            comma++;
        }
        return ans;
    }
};