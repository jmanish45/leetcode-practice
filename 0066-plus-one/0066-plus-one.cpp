class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i = n-1; i>=0; i--){
            int new_digit = digits[i]+carry;
            if(new_digit>=10) {
                digits[i]=0;
                carry = 1;

            }
            else {
                digits[i]=new_digit;
                carry = 0;
                break;
            }
        }
        if(carry == 1) {
            vector<int> new_digits(n+1,0) ;
                new_digits[0]=1;
                for(int i = 1; i<n+1;i++) {
                    new_digits[i]=digits[i-1];
                }
                return new_digits;
            
        }
        return digits;
    }
};