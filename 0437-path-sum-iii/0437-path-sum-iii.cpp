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
    void solve(TreeNode* root, int& count, long long targetSum , long long sum) {
        if(!root) return ;
        sum+=(long long) root->val;
        if(sum==targetSum) {
            count++;
            
        }
        solve(root->left, count, targetSum, sum);
        solve(root->right, count, targetSum, sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        if(!root) return  0;
        solve(root, count, (long long) targetSum, 0);
        count+= (pathSum(root->left, targetSum) + pathSum(root->right, targetSum));
        return count;
    }
};