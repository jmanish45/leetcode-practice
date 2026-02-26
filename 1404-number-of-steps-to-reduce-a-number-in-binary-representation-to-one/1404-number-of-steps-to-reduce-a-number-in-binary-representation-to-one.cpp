class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        //every even number has its last bianry digit as 0 and 
        //every odd number has its last digit as 1 
        while(s!="1") {
            int i = s.length()-1;
            if(s[i]=='0') s.pop_back();
            else {
                while(i>=0 && s[i]=='1') {
                    s[i] = '0';
                    i--;
                }
                if(i>=0) {
                    s[i]='1';
                }
                else {
                    s = '1'+s;
                }
            }
            steps++;
        }
        return steps;
    }
};