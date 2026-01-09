class Solution {
public:
    
    TreeNode* dfs(TreeNode* root ) {
        if(!root) return NULL;

        int leftdepth = level(root->left);
        int rightdepth = level(root->right);
        
        if(leftdepth==rightdepth) return root;
        else if(leftdepth>rightdepth) return dfs(root->left);
        else return dfs(root->right);
    }
    
    int level(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + max(level(root->left) , level(root->right))     ; 
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        return dfs(root);
    }
};