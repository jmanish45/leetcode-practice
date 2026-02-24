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
    int ans;
    void solve2(vector<int> path) {
        int dec= 0;
        int mult = 1;
        for(int i=path.size()-1; i>=0; i--) {
            dec = dec + (mult*path[i]);
            mult*=2;
        }
        ans+=dec;
    }
    void solve(TreeNode* root, vector<int>& path) {
        if(!root) {
            return;
        }
        path.push_back(root->val);
        if(!root->left && !root->right) {
            solve2(path);
        }
        else {
            solve(root->left, path);
            solve(root->right, path);
        }
        path.pop_back();
    }
    int sumRootToLeaf(TreeNode* root)  {
        ans = 0;
        vector<int> path;
        solve(root, path);
        return ans;
    }
};