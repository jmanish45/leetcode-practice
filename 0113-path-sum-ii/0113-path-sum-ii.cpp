/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int sum, int targetSum, vector<vector<int>> &result, vector<int>& path) {
        if(!root) return;
        path.push_back(root->val);
        sum+=root->val;
        if(!root->left && !root->right && targetSum==sum) {
            result.push_back(path);
        }

        solve(root->left, sum, targetSum, result, path);
        solve(root->right, sum, targetSum, result, path);

        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        solve(root, 0, targetSum, result, path);
        return result ;
    }
};