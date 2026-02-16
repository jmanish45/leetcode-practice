class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binary(32, '0');
        int i = 0;

        while(n > 0 ) {
            int rem = n % 2;
            binary[i] = rem + '0';
            i++;
            n = n / 2;
        }

        uint32_t ans = 0;
        uint32_t mult = 1;

        for(int i = 31; i >= 0; i--) {
            ans += mult * (binary[i] - '0');
            mult *= 2;
        }

        return ans;
    }
};
