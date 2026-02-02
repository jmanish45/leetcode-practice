class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i<=31; i++) {
            int temp = (1<<i) ;
            int countOnes = 0;
            for(auto& num : nums) {
                if(num & temp) countOnes++;
            }
            if(countOnes % 3 == 1) result = (result | (1<<i) ) ;
        }
        return result;
    }
};