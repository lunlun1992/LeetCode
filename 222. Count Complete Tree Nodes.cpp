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
    int dfs(TreeNode *node, int leftlen, int rightlen)
    {
        if(NULL == node)
            return 0;
        int lleft = 0;
        int rright = 0;
        
        TreeNode *n = node;
        if(leftlen == -1)
        {
            while(n != NULL)
            {
                n = n->left;
                lleft++;
            }
            leftlen = lleft;
        }
        
        n = node;
        if(rightlen == -1)
        {
            while(n != NULL)
            {
                n = n->right;
                rright++;
            }
            rightlen = rright;
        }
        if(leftlen == rightlen)
            return (1 << leftlen) - 1;
        else
            return 1 + dfs(node->left, leftlen - 1, -1) + dfs(node->right, -1, rightlen - 1);
    }
    int countNodes(TreeNode* root) 
    {
        return dfs(root, -1, -1);    
    }
};