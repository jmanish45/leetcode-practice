class Solution {
public:
    typedef long long ll;
    void dfs(int i, unordered_set<int>& visited, unordered_map<int, vector<int>> &adj) {
        visited.insert(i);
        for(auto& v : adj[i]) {
            if(visited.find(v)==visited.end()) {
                dfs(v, visited, adj);
            }
        }


    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i<n; i++)  {
            for(int j=0; j<n; j++) {
                if(i==j) continue ;
                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];

                ll dist = ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
                if((ll)r1*r1>=dist) {
                    adj[i].push_back(j);
                }

            }
        }

        //all the points which are connected to each other with a radius are in adj 
        //now applying bfs to get the max bombs geting explode at once with any one bomb first  blasted
        int maxi = 0;
        unordered_set<int> visited;
        for(int i=0; i<n; i++) {
            dfs(i, visited, adj);
            int count = visited.size();
            maxi = max(maxi,  count);
            visited.clear();
        }

        return maxi;
    }
};