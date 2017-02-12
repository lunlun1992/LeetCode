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
    bool a(TreeNode *l, TreeNode *r)
    {
        if(!l && !r)
            return true;
        else if(!l || !r)
            return false;
        if(l->val != r->val)
            return false;
        return a(l->left, r->right) && a(l->right, r->left); 
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        return a(root->left, root->right);
    }
};