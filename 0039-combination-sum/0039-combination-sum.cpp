class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int start) {
        if (target == 0) { // Base case: Target is reached
            result.push_back(current);
            return;
        }
        if (target < 0) return; // Base case: Target is exceeded

        for (int i = start; i < candidates.size(); ++i) {
            current.push_back(candidates[i]); // Choose the candidate
            backtrack(candidates, target - candidates[i], result, current, i); // Explore further with the same candidate
            current.pop_back(); // Undo the choice (backtrack)
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, result, current, 0);
        return result;
    }
};
