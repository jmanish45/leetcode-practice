
class Solution {
public:
    int nthlevelsum(TreeNode* root, int targetlevel, int currlevel) {
        if(!root) {
            return 0;
        }
        if(currlevel == targetlevel) {
            return root->val;
        }
        return nthlevelsum(root->left, targetlevel, currlevel+1) + nthlevelsum(root->right, targetlevel, currlevel+1);

    }
    bool hasNodes(TreeNode* root, int targetlevel, int currlevel) {
        if (!root) return false;
        if (currlevel == targetlevel) return true;

        return hasNodes(root->left, targetlevel, currlevel + 1) ||
               hasNodes(root->right, targetlevel, currlevel + 1);
    }
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int level = 1;
        int maxsum = INT_MIN;
        while(hasNodes(root, level, 1)) {
            int sum = nthlevelsum(root, level, 1) ;
            
            if(sum > maxsum) {
                maxsum = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};