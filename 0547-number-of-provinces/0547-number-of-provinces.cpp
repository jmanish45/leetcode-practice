class Solution {
public:
    void dfs(int node,  vector<int> list[], vector<bool> &visit) {
        visit[node] = 1;
        for(auto it : list[node]) {
            if(visit[it]==0) {
                dfs(it,  list, visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& matrix) {
        int v = matrix.size();
        vector<int> list[v];
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(matrix[i][j]==1 && i!=j && i<j) {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        vector<bool> visit(v, false);
        int count = 0;
        for(int i=0; i<v ; i++) {
            if(visit[i]==false) {
                count++;
                dfs(i, list, visit);
            }
        }
        return count;
    }
};