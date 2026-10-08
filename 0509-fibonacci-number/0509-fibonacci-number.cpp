// class Solution {
// public:
//     int fibo(int n, vector<int> &dp) {
//         if(n<=1) return n;
//         if(dp[n]!=-1) return dp[n];
//         dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
//         return dp[n];
//     }
//     int fib(int n) {
//        vector<int> dp(n+1, -1);
//        return fibo(n, dp); 
//     }
// };
// class Solution {
// public:
    
//     int fib(int n) {
//     if(n<=1) return n;
//     vector<int> dp(n+1);
       
//     for(int i = 0; i<=n; i++) {
//         if(i<=1) dp[i] = i;
//         else dp[i] = dp[i-1] + dp[i-2];
//     }
//     return dp[n]; 
//     }
// };
class Solution {
public:
    int f(int n) {
        if(n<=1) return n;
        return f(n-1) + f(n-2);
    }
    int fib(int n) {
        return f(n);
    }
};