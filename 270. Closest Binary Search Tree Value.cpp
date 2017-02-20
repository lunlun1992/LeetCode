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
    int closestValue(TreeNode* root, double target)
    {
        if(abs(root->val - target) < 1e-15)
            return root->val;
        TreeNode *next = root->val < target ? root->right : root->left;
        cout << "here" << endl;
        if(!next)
            return root->val;
        int n = closestValue(next, target);
        return abs(root->val - target) < abs(n - target) ? root->val : n;
    }
};