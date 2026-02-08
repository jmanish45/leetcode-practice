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
    int level(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(level(root->left), level(root->right));

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int bal = level(root->left) - level(root->right) ;
        if(bal>=2 || bal<=-2) {
            return false;
        }

        bool isleftbalanced = isBalanced(root->left);
        bool isrightbalanced = isBalanced(root->right);

        return isleftbalanced && isrightbalanced;

    }
};