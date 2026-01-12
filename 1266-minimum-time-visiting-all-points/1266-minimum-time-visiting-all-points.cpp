class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int totalTime = 0;
        vector<int> fv = points[0];
        for(int i=1; i<n; i++) {
            vector<int> sv = points[i];
            int xdiff = sv[0] - fv[0];
            int ydiff = sv[1] - fv[1];
            totalTime = totalTime + max(abs(xdiff), abs(ydiff));
            fv = points[i];
        }
        return totalTime;
    }
};