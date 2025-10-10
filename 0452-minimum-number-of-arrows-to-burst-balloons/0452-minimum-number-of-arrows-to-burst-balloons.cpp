class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> ans;
        sort(points.begin(), points.end());
        //[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
        //[[1,10],[3,9],[4,11],[6,7],[6,9][8,12],[9,12]]
        int count = 1;
        int start = points[0][1];
        for(int i = 1; i<n; i++) {
            if(points[i][0]>start) {
                start = points[i][1];
                count++;
            }
            else {
                start = min(start, points[i][1]);
            }
        }
        
        return count;
    }
};