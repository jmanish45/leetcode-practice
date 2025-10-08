class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(), a.end());
        long long n = a.size();
        long long sum = mass;
        for(long long i = 0; i<n; i++) {
            if(a[i]<=sum) {
                sum+=a[i];
                if(sum>=a[n-1]){
                    return true;
                }
            }
            else {
                return false;
            }
            
        }
        return true;
    }
};