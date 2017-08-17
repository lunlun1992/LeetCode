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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int llen = 0;
        int rlen = 0;
        TreeNode *node = root;
        while (node) {
            llen++;
            node = node->left;
        } 
        node = root;
        while(node)
        {
            rlen++;
            node = node->right;
        }
        
        if(llen == rlen)
            return (1 << llen) - 1;
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
};