class Solution {
public:
    int old_color;
    int m, n;
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0, 1,0,-1};
    void dfs(int i , int j , int color, vector<vector<int>>& image ) {
        if(i>=m || j>=n || i<0 || j<0) return;
        if(image[i][j]!=old_color) return ;
        image[i][j] = color;
        for(int k = 0; k<4; k++) {
            dfs(i+dx[k], j+dy[k], color, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        old_color = image[sr][sc];
        m = image.size();
        n = image[0].size();
        dfs(sr, sc, color, image);
        return image;
    }
};