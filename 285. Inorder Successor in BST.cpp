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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode *node = root;
        TreeNode *smallest = NULL;
        while(1)
        {
            if(!node)
                return smallest;
            if(node->val <= p->val)
                node = node->right;
            else//如果大，则本节点和左子树都有可能，所以要保存本节点。并且搜索左子树
            {
                if(!smallest || smallest->val > node->val)
                    smallest = node;
                node = node->left;
            }
        }
    }
};