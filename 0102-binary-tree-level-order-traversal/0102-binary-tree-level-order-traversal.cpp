class Solution {
public:
    int level(TreeNode*  root) {
        if(!root) return NULL;
        return 1 + max(level(root->left), level(root->right));
    }
    void nthlevel(TreeNode* root, int currlevel, int level, vector<int>& v ) {
        if(!root) return;
        if(currlevel==level) {
            v.push_back(root->val);
            return ;
        }
        nthlevel(root->left, currlevel+1, level, v);
        nthlevel(root->right, currlevel+1, level, v);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int n = level(root);
        for(int i = 1; i<=n ;i++) {
            vector<int> v;
            nthlevel(root, 1, i, v);
            ans.push_back(v);
        }
        return ans;
    }
};