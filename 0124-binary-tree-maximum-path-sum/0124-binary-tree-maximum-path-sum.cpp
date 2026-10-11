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
    int maxsum ;
    int solve(TreeNode* root) {
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);

        int only_one_path = max(left, right) + root->val;
        int only_root  = root->val;
        int curl_path = left+right+root->val;
        maxsum = max({maxsum, only_one_path, only_root, curl_path});
        return max(only_one_path, only_root);
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};