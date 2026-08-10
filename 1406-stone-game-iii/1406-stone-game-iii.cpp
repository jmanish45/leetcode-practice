class Solution {
public:
    int n;
    vector<int> t;
    vector<bool> visit;
    int solve(int idx, vector<int>& stone) {
        if(idx>=n) return 0;
        if(visit[idx]) return t[idx];
        visit[idx] = true;
        int result = stone[idx]-solve(idx+1, stone);
        if(idx+1<n) {
            result = max(result, stone[idx]+stone[idx+1] - solve(idx+2, stone));
        }
        if(idx+2<n) {
            result = max(result, stone[idx]+stone[idx+1]+stone[idx+2]-solve(idx+3, stone));
        }
        return t[idx] = result;

        
    }
    string stoneGameIII(vector<int>& stone) {
        n = stone.size();
        //will find the diff of the score of Alice and Bod
        //diff = Alice - Bob
        t.resize(n+1,-1);
        visit.resize(n+1, false);
        int diff = solve(0,stone);
        
        if(diff>0) {
            return "Alice";
        }
        else if(diff<0) {
            return "Bob";
        }
        return "Tie";
    }
};