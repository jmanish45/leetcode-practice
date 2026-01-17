class Solution {
public:
    bool isintersect(vector<int>& bl1, vector<int>& tr1, vector<int>& bl2 , vector<int>& tr2) {
        //for x-axis intersection check if they overlap
        if(tr1[0]<=bl2[0] || tr2[0]<=bl1[0]) return false;
        
        //check for y overlap
        if(tr1[1]<=bl2[1] || tr2[1]<=bl1[1]) return false;

        return true;
    }
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n = bl.size();
        long long maxarea = 0;
        for(int i=0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(isintersect(bl[i], tr[i], bl[j], tr[j])) {
                    int xintersect = min(tr[i][0], tr[j][0]) - max(bl[j][0], bl[i][0]);
                    int yintersect = min(tr[i][1], tr[j][1]) - max(bl[j][1], bl[i][1]);
                    int side = min(xintersect, yintersect);
                    
                    maxarea = max(1LL*side*side, maxarea);
                }
            }
            
        }
        return maxarea;
    }
};