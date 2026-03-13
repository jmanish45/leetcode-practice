class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int zeroleft, int oneleft, bool isLastOne, int limit) {
        if(zeroleft == 0 && oneleft == 0) {
            return 1;
        }

        if(t[zeroleft][oneleft][isLastOne] != -1) {
            return t[zeroleft][oneleft][isLastOne];
        }

        long long result = 0;

        if(isLastOne) {
            for(int len = 1; len <= min(zeroleft, limit); len++) {
                result = (result + solve(zeroleft-len, oneleft, false, limit)) % M;
            }
        } 
        else {
            for(int len = 1; len <= min(oneleft, limit); len++) {
                result = (result + solve(zeroleft, oneleft-len, true, limit)) % M;
            }
        }

        return t[zeroleft][oneleft][isLastOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));

        int startWithOne = solve(zero, one, false, limit);
        int startWithZero = solve(zero, one, true, limit);

        return (startWithOne + startWithZero) % M;
    }
};