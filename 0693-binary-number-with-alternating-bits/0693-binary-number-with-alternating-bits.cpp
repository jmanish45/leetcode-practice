class Solution {
public:
    bool hasAlternatingBits(int n) {
        // 5 -> 1 0 1
        
        
        int now = (n  & 1 );  //now = 1
        for(int i = 1; (n>>i) > 0 ; i++) {
            int next = !now;
            now = (n & (1<<i)) ? 1 : 0 ;
            if(now != next) return false;
        }
        return true;
    }
};

// 7 = 1 1 1