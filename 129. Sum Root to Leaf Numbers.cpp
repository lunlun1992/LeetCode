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
    void dfs(TreeNode *root, int pre) {
        int now = pre * 10 + root->val;
        if (!root->left && !root->right) {
            sum += now;
        }
        if (root->left) {
            dfs(root->left, now);
        }
        if (root->right) {
            dfs(root->right, now);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root, 0);
        return sum;
    }
private:
    int sum;
};