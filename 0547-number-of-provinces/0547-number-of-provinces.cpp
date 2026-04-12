class Solution {
public:
    
    void dfs(int i, unordered_map<int, vector<int>>& adj,  vector<bool>& visited) {
        visited[i] = true;
        for(auto& neig : adj[i]) {
            if(!visited[neig]) dfs(neig, adj, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        unordered_map<int , vector<int>> adj;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]==1 && i!=j) {
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count; 
    }
};