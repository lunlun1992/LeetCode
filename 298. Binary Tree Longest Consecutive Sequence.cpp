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
    int longestConsecutive(TreeNode* root)
    {
        if(!root)
            return 0;
        maxi = INT_MIN;
        dfs(root, root->val);
        return maxi;
    }
private:
    int maxi;
    int dfs(TreeNode *node, int val)
    {
        if(!node)   
            return 0;
        int now = 1 + max(dfs(node->left, node->val + 1), dfs(node->right, node->val + 1));
        maxi = max(maxi, now);
        if(node->val == val)
            return now;
        else
            return 0;
    }
};