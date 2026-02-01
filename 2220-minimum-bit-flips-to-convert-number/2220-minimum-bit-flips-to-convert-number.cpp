class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorop = start^goal;
        int count = 0;
        //start = 1010 goal = 0111
        //start^goal = 1101


        for(int i=0; i<31; i++) {
             if((xorop & (1<<i))!=0) count++;   

        }
        return count ;
    }
};