class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        reverse(piles.begin(), piles.end());
        int tot = 0;
        for(int i=0; i<n; i++) {
            tot+=piles[i];
        }
        int alice = 0;
        for(int i=0; i<n; i+=2) {
            alice+=piles[i];
        }
        if(alice>tot/2) return true;
        else return false;
    }
};