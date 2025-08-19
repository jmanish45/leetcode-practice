class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long cont = 0;
        for(int num : nums) {
            if(num==0) {
                cont++;
                count+=cont;
            }
            else {
                cont=0;
            }
        }
        return count;
    }
};