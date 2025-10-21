class Solution {
public:
    const long long MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        long long n = arr.size();
        long long sum =  0;
        vector<long long> times(n, 1); //1, 6, 2, 1 
        for(long long i = 0; i<n; i++) {
            long long left = i-1;
            long long right = i+1;
            long long leftscore = 1;
            while(left>=0) {
                if(arr[i]<arr[left]) {
                    times[i]++;
                    left--;
                    leftscore++;
                }
                
                else break;
            }
            while(right<n) {
                if(arr[i]<=arr[right]) {
                    times[i]+=leftscore;
                    right++;
                }
                else break;
            }

        }
        for(long long i = 0; i<n ; i++) {
            long long mult = times[i]*arr[i];
            sum%=MOD;
            sum+=mult;
        }
        return sum;
    }
};