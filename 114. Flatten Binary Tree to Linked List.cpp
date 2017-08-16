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
    void flatten(TreeNode* root) {
        TreeNode *node = root;
        while (node) {
            if (node->left) {
                TreeNode *tmp = node->left;
                while (tmp->right) tmp = tmp->right;
                tmp->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};