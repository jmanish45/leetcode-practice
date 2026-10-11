class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0; i<=sqrt(c); i++) {
            int a = i*i;
            int b = (c-a);
            int d = sqrt(b);
            if(d*d+a==c) return true;
            
        }
        return false;
    }
};