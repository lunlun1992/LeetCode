/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    void dfs(int d, TreeNode *r) {
        if(!r->left && !r->right) {
            maxi = max(maxi, d);
            return;
        }
        if(r->left)
            dfs(d + 1, r->left);
        if(r->right)
            dfs(d + 1, r->right);      
    }
    int maxDepth(TreeNode* root) {
        maxi = 0;
        if(!root)
            return 0;
        dfs(1, root);
        return maxi;
    }
private:
    int maxi;
};