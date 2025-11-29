class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long moves = 0;
        
        sort(nums.begin(),nums.end());
        for(int i=1; i<n; i++) {
            moves+=((long long)nums[i]-nums[0]);   
        }
        return moves;
    }
};