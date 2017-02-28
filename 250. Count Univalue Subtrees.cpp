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
    bool help(TreeNode* root, int &count)
    {
        if(!root)
            return true;
        bool bl = help(root->left, count);
        bool br = help(root->right, count);
        if(bl && br && ((!root->left || root->left->val == root->val) && (!root->right || root->right->val == root->val)))
        {
            count++;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) 
    {
        int count = 0;
        help(root, count);
        return count;
    }
};