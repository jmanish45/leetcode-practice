/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int level(Node* root) {
        if(!root) return 0;
        int maxlev = 0;
        for(Node* child : root->children) {
            maxlev = max(maxlev, level(child));
        }
        return 1 + maxlev;
    }
    void nthlevel(Node* root, int curr, int target, vector<int>& v) {
        if(!root) return ;
        if(curr==target) {
            v.push_back(root->val);
            return;
        }
        for(Node* child : root->children) {
            nthlevel(child, curr+1, target, v);
        }

    }
    vector<vector<int>> levelOrder(Node* root) {
        int n = level(root);
        vector<vector<int>> ans;
        for(int i=1; i<=n; i++) {
            vector<int> v;
            nthlevel(root, 1, i, v);
            ans.push_back(v);
        }
        return ans;
    }
};