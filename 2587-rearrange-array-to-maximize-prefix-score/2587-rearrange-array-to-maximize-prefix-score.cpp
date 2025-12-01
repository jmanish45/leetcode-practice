class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        long long prefix = 0;
        int count  = 0;
        for(int x : nums) {
            prefix+=x;
            if(prefix>0) count++;
            else break;
        }
        return count ;

    }
};