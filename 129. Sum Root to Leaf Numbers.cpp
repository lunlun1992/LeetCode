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
    void dfs(TreeNode *r, int num)
    {
        if(!r->left && !r->right)
            sum += num * 10 + r->val;
        else if(!r->left)
            dfs(r->right, num * 10 + r->val);
        else if(!r->right)
            dfs(r->left, num * 10 + r->val);
        else
        {
            dfs(r->left, num * 10 + r->val);
            dfs(r->right, num * 10 + r->val);
        }
            
    }
    int sumNumbers(TreeNode* root) 
    {
        if(!root)
            return 0;
        sum = 0;
        dfs(root, 0);
        return sum;
    }
private:
    int sum;
};