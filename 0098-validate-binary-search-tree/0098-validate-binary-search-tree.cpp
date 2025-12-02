
// class Solution {
// public:
//     long long maxtree(TreeNode* root) {
//         if(root== NULL) return LLONG_MIN;
//         else return max((long long)(root->val), max(maxtree(root->left), maxtree(root->right)));
//     }
//     long long mintree(TreeNode* root) {
//         if(root== NULL) return LLONG_MAX;
//         else return min((long long)(root->val), min(mintree(root->left), mintree(root->right)));
//     }

//     bool isValidBST(TreeNode* root) {
//         if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
//         else if((long long)root->val <= maxtree(root->left )) return false;
//         else if((long long)root->val >= mintree(root->right)) return false;
//         return (isValidBST(root->left) &&  isValidBST(root->right));
       
//     }
// };
// second method using inorder approach as all elements are arranged in ascending order here 
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans) {
        if(root==NULL) return ;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    
    
    }

    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorder(root , ans);
        for(int i = 1; i< ans.size(); i++) {
            if(ans[i]<=ans[i-1]) return false;
        }
        return true;
    }
};
