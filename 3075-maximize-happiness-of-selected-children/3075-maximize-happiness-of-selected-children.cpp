class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());  //[1,12,42]
        int d = 0; 
        long long ans = 0;      
        for(int i=n-1; i>=0; i--) {
            if((happiness[i]-d) >= 0) happiness[i]-=d;
            else happiness[i]=0;
            if(k>0) {
                ans+=happiness[i];
                k--;
            }
            d++;
            if(k==0) break;

        }
        return ans;

    }
};