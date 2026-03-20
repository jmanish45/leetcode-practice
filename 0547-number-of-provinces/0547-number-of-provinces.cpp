class Solution {
public:
    void dfs(int node, vector<int> list[], vector<bool>& visited) {
        visited[node] = true;
        for(auto &neigh : list[node]) {
            if(visited[neigh]==false) {
                dfs(neigh, list, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& matrix) {
        int v = matrix.size() ;// v -> no of total vertices

        //create an array of vectors to store all the vertices with their neighbours
        vector<int> list[v];

        for(int i=0; i<v; i++) {
            for(int j = 0; j<v; j++) {
                if(matrix[i][j]==1 && i!=j && i<j) {
                    list[i].push_back(j);
                    list[j].push_back(i);

                }
            }
        }

        //now from about iterations all the vertices are stored with theiri connected nodes

        //now to count the no of seperate connectiojs using dfs 

        int count = 0;
        vector<bool> visited(v, false);
        for(int i = 0; i<v; i++) {
            if(visited[i]==0) {
                count++;
                dfs(i, list, visited);
            }

        }

        return count;
    }
};