class Solution {
public:
    vector<vector<int>> d{{-1,0}, {1,0},{0,-1}, {0,1}};
    typedef pair<int,int> P;
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //we wiil use BFS method to simultanoiusly cover all the rotten at once affecting their adjacent oranges 

        //for bfs we use Queue data structure
        queue<P> q;


        int fresh = 0;

        //in this for loop we will stre the coords where there is rotten orange annd also count the no of fresh ones in grid
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
                if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }

        //applying bfs on the queue for all the coords wwe will check for the neighbout fresh ones and stpre in the queue if not rotten and then rot them and also increment the minute when the queue gets empty for that one round 
        int minutes = 0;
        while(!q.empty()) {
            int N = q.size();
            bool flag = false;
            while(N--) {
                
                P front = q.front();
                q.pop();
                int i = front.first;
                int j = front.second;
                for(int k = 0; k<4; k++) {
                    int new_i = i + d[k][0];
                    int new_j = j + d[k][1];

                    if(new_i>=0 && new_j>=0 && new_i<m && new_j<n) {
                        if(grid[new_i][new_j]==1) {
                            flag  = true;
                            grid[new_i][new_j] = 2;
                            fresh--;
                            q.push({new_i,new_j});
                        }
                    }
                }
            }
            if(flag==true) minutes++;
        }
        cout<<fresh<<" "<<minutes;
        return (fresh==0) ? minutes : -1 ;
     }
};