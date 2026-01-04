class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalsum = 0;
        
        for(int num : nums) {
            int count  = 0;
            int sum = 0;
            for(int d = 1; d <= num ; d++) {
                if(num%d==0) {
                    count++;
                    sum+=d;
                }
                if(count>4) break;
                
            }
            if(count==4) totalsum+=sum;
            sum = 0;
            count =  0;
        }
        return totalsum;
    }

};