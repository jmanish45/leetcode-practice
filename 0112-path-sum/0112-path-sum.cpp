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
    bool helper(TreeNode* root, int sum, int target) {
        if(!root) return false;;
        sum += root->val;
        if(!root->left && !root->right) {
            return target == sum;
        }
        return (helper(root->left, sum, target)) || helper(root->right, sum, target);

    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, 0, targetSum);    
    }
};