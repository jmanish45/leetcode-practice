class Solution {
public:
    bool isPossible(int speed, vector<int>& piles, int h ) {
        int n = piles.size();
        int timereq = 0;
        for(int i =0; i<n; i++) {
            if(timereq>h) return false;
            if(speed>=piles[i]) timereq+=1;
            else  {
                if(piles[i]%speed==0) timereq+=(piles[i]/speed);
                else timereq+=((piles[i]/speed)+1);
            }
        }
        if(timereq>h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx = -1;
        for(int i=0; i<n; i++) {
            mx = max(piles[i], mx);
        }
        int lo = 1; //min speed will be 1 to eat atleast one banana in 1 hour
        int hi = mx;
        int ans = 1;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(isPossible(mid, piles, h)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid+1;
            }
        }
        return ans;
    }
};