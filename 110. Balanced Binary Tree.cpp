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
    int depth(TreeNode *r) {
        if(!r)
            return 0;
        int left = depth(r->left);
        if(left == -1)
            return -1;
        int right = depth(r->right);
        if(right == -1)
            return -1;
        return abs(left - right) <= 1 ? 1 + max(left, right) : -1;
    }
    

    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;    
    }
};