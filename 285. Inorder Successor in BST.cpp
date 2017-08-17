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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *node = root;
        TreeNode *smallest = NULL;
        for (;;) {
            if (!node)
                return smallest;
            if (node->val <= p->val) {
                node = node->right;
            } else {    //node->val > p->val
                if(!smallest || smallest->val > node->val)
                    smallest = node;
                node = node->left;
            }
        }
    }
};