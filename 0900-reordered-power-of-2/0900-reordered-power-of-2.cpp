class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> count(10,0);
        while(n>0) {
            int digit = n%10;
            count[digit]++;
            n=n/10;
        }
        long long power = 1;
        long long temp = 0;
        for(int i = 0; i<31 ; i++) {
            temp = power;
            vector<int> check(10,0);
            while(temp>0) {
                int dig = temp%10;
                check[dig]++;
                temp/=10;
            }
            if(count==check) return true;
            power*=2;
        }
        return false;
    }


};