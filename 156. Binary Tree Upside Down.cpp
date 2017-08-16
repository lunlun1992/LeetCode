/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//奇怪的需求，不过可以用递归的方法解决
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left)
            return root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        TreeNode *ret = upsideDownBinaryTree(left);
        left->left = right;
        left->right = root;
        root->left = root->right = NULL;
        return ret;
    }
};