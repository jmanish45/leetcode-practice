class Solution {
public:
    int countCommas(int n) {
        if(n>=100000) return n - 1000 + 1;
        int diff = n - 1000 + 1;
        if(diff<0) return 0;
        else return diff ;
    }
    
};