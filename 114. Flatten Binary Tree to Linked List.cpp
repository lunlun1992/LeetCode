/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//把左子树接到右子树上去
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(NULL == root)
            return;
        TreeNode *node = root;
        while(node)
        {
            TreeNode *n = node->left;
            if(n)
            {
                while(n->right)
                    n = n->right;
                n->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};