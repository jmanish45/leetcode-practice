class Solution {
public:
    
    long long maxproduct = 0;
    long long mod = 1000000007;
    unordered_map<TreeNode* , long long> mp;

    long long getnodesum(TreeNode* root) {
        if(root==NULL) return 0;
        long long sumval = root->val + (getnodesum(root->left) + getnodesum(root->right));
        mp[root] = sumval;
        return sumval;
    }
    int maxProduct(TreeNode* root) {
        long long totsum = getnodesum(root);
        for(auto &x : mp) {
            long long s1 = x.second;
            long long s2 = totsum - s1;
            maxproduct = max(maxproduct, s1*s2);
            
        }
        return maxproduct%mod ;
    }
};