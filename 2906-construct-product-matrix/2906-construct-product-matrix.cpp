class Solution {
public:
    int mod = 12345;
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        // 1 2
        // 3 4
        
        //prefix -> 
        // 1 1
        // 2 6

        //suffix ->
        //24 12
        //4 1

        //product -> 
        // 24 12 
        // 8 6
        
        vector<int> nums;
        for(int i =0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        int s = nums.size();
        vector<int> prefix(s, 1);
        for(int i=1; i<s; i++) {
            prefix[i] = (1LL * prefix[i-1] * nums[i-1])%mod;
            
        }

        vector<int> suffix(s,1);
        for(int i = s-2; i>=0 ;i--) {
            suffix[i] =( 1LL * suffix[i+1]*nums[i+1])%mod;
            
        }
        
        for(int i=0; i<s; i++) {
            nums[i] = (1LL * prefix[i]*suffix[i])%mod;
            
        }
        int idx = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = nums[idx++];
            }
        }

        return grid;
    }
};