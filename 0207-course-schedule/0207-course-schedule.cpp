class Solution {
public:
    bool isCycle(unordered_map<int,vector<int>> &adj,
    int i, vector<bool> &visited, vector<bool> &inRecursion)
        {
            visited[i] = true;
            inRecursion[i] = true;
            for(auto &v : adj[i]) {
                if(!visited[v]) {
                    if(isCycle(adj, v, visited, inRecursion)) {
                        return true;
                    }
                }
                else if(inRecursion[v]==true) {
                    return true;
                }   
            }
            inRecursion[i] = false;
            return false;
        }
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        for(auto& vec : pre) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                if(isCycle(adj, i, visited, inRecursion))
                    return false;
            }
        }
        return true;
    }
};