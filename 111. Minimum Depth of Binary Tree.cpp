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

    int minDepth(TreeNode* root) {
        if(root == NULL)
             return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(root->left != NULL && root->right != NULL)
             return left < right ? left + 1 : right + 1;
        else if(root->left == NULL)
             return right + 1;
        else
             return left + 1;    
    }
};