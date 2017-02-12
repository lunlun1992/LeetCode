/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//当需要直通叶子节点时，要判断是否存在孩子
class Solution {
public:
    bool a(TreeNode *r, int sum)
    {
        if(!r && sum == 0)
            return true;
        else if(!r && sum != 0)
            return false;
        if(r->left && r->right)
            return a(r->left, sum - r->val) || a(r->right, sum - r->val);
        else if(r->left)
            return a(r->left, sum - r->val);
        else
            return a(r->right, sum - r->val);
    }
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(!root)
            return false;
        
        return a(root, sum);
    }
};