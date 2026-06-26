class Solution {
public:
    int t[201][201][2];
    int mod = 1e9+7;
    int solve(int zeroleft, int oneleft, bool lastwasone, int limit) {
        if(zeroleft==0 && oneleft==0) return 1;
        if(t[zeroleft][oneleft][lastwasone]!=-1) 
            return t[zeroleft][oneleft][lastwasone];
        int result=0;
        if(lastwasone) {
            for(int len = 1 ; len<=min(zeroleft , limit); len++) {
                result = (result+solve(zeroleft-len, oneleft, false, limit))%mod;
            }
        }
        else {
            for(int len = 1; len<=min(oneleft, limit); len++) {
                result =( result + solve(zeroleft, oneleft-len, true, limit))%mod;
            }
        }
        return t[zeroleft][oneleft][lastwasone] = result;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int startwithzero = solve(zero , one, true, limit);
        int startwithone = solve(zero, one, false, limit);
        
        return (startwithzero + startwithone)%mod ; 
    }
};