class Solution {
public:
    bool judgeCircle(string moves) {
        //robot starts at (0,0);
        //start : i = 0, j = 0;
        //UP : i-1, j=0;
        //DOwn : i+1, j=0;
        //R : i , j+1,
        //L : i, j-1,
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int n = moves.length();
        int k = -1;
        int new_i = 0;
        int new_j = 0;
        for(int i = 0; i<n; i++) {
            if(moves[i]=='U') k = 0;
            else if(moves[i]=='D') k = 1;
            else if(moves[i]=='R') k = 2;
            else k = 3;
            new_i = new_i + dir[k][0];
            new_j = new_j + dir[k][1];
            
        }
        if(new_i == 0 && new_j == 0) return true;
        else return false;
    }
};