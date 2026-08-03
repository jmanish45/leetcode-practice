class Solution {
public:
    int n;
    vector<int> vis;
    bool solve(vector<int>& arr, int i) {
        if(i>=n || i<0 ) return false;
        if(arr[i]==0) return true;
        if(vis[i]==1) return false;
        bool can = false;
        vis[i] = true;
        can = can || solve(arr, i+arr[i]) || solve(arr, i-arr[i]);
        return can;
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vis.resize(n,0);
        return solve(arr, start);
    }
};