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
    vector<int> vec;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
        return;
    }
    TreeNode* construct(int l, int r){
        if(l>r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = construct(l, mid-1);
        root->right = construct(mid+1, r);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int l = 0, r = vec.size()-1;
        return construct(l,r);
    }
};