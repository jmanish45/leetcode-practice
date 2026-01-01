class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> result(n,0);
        int carry = 1;
        
        for(int i=n-1; i>=0; i--) {
            int d = digits[i]+carry;
            if(d>9) {
                carry = 1;
                result[i] = d%10;
            } 
            else {
                carry = 0;
                result[i] = d;
            }
        }
        vector<int> result2(n+1, 0);
        result2[0] = 1;
        if(carry==1) {
            for(int i=1 ; i<=n; i++) {
                result2[i] = result[i-1];
            }
            return result2;
        }
        return result;
    }
};