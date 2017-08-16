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
    bool help(TreeNode *r, int sum) {
        if(!r && sum == 0)
            return true;
        else if(!r && sum != 0)
            return false;
        if(r->left && r->right)
            return help(r->left, sum - r->val) || help(r->right, sum - r->val);
        else if(r->left)
            return help(r->left, sum - r->val);
        else
            return help(r->right, sum - r->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;      
        return help(root, sum);
    }
};