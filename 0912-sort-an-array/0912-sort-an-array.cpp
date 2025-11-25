class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int> , greater<int> > pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);

        }
        vector<int> ans;
        while(pq.size()>0) {
            int a = pq.top();
            pq.pop();
            ans.push_back(a);
        }
        return ans;
    }
};