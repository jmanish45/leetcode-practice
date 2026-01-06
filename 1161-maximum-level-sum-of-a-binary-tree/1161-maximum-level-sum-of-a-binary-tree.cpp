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
    int nthlevelsum(TreeNode* root, int targetlevel, int currlevel) {
        if(!root) return 0;
        if(targetlevel==currlevel) {
            return root->val;
        }
        return nthlevelsum(root->left,  targetlevel,  currlevel+1) + nthlevelsum(root->right,  targetlevel,  currlevel+1) ;
    } 
    bool haschild(TreeNode* root, int targetlevel, int currlevel) {
        if(root==NULL) return false;
        if(targetlevel==currlevel) {
            return true;
        }
        return haschild(root->left, targetlevel, currlevel+1) || haschild(root->right, targetlevel, currlevel+1);


    }
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int level = 1;
        int maxsum = INT_MIN;

        while(haschild(root, level, 1)) {
            int sum = nthlevelsum(root, level, 1) ;
            if(maxsum<sum) {
                maxsum = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};