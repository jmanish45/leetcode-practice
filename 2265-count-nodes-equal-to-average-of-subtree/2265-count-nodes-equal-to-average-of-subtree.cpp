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
    int findsum(TreeNode* root, int &count) {
        if(!root) return 0;
        count++;
        int left = findsum(root->left, count);
        int right = findsum(root->right, count);
        return left+right+root->val; 
    }
    void solve(TreeNode* root, int &result) {
        if(!root) return ;
        int count = 0 ;
        int sum = findsum(root, count);
        if(root->val == sum/count) result+=1;   
        solve(root->left, result);
        solve(root->right, result);     

    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};