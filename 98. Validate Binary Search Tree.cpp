/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//固定子树的值范围。
class Solution {
public:
    bool help(int64_t mini, int64_t maxi, TreeNode *r) {
        if(!r)
            return true;
        int64_t val = (int64_t)r->val;
        if(val <= mini || val >= maxi)  
            return false;
        return a(mini, val, r->left) && a(val, maxi, r->right);
        
    }
    bool isValidBST(TreeNode* root) {
        return help(-2147483650, 2147483648, root);    
    }
    
};