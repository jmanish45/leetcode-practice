class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& mp, vector<bool>& visited, int i) {
        visited[i] = true;
        for(auto& v : mp[i]) {
            if(!visited[v]) {
                dfs(mp, visited, v);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]==1) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                
                dfs(mp, visited, i);
                count++;
            }
        }
        return count;
    }
};