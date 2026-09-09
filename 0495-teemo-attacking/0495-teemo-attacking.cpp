class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int dur) {
        //[1,2]  , 2
        // 1 -> 2 
        int ans  = 0;
        int n = time.size();
        
        for(int i=1 ; i<n ; i++) {
            if(time[i-1]+(dur-1)>=time[i]) ans+=(time[i]-time[i-1]) ;
            else ans+=dur;
        }
        ans+=dur;
        return ans;
    }
};