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

    vector<string> binaryTreePaths(TreeNode* root)
    {
        if(!root)
            return ret;
        rr = root;
        dfs(root);
        return ret;
    }
private:
    vector<string> ret;
    string now;
    TreeNode *rr;
    void dfs(TreeNode *node)
    {
        TreeNode *r = node->right;
        TreeNode *l = node->left;
        string now_bak = now;
        if(node == rr)
            now += to_string(node->val);
        else
            now += "->" + to_string(node->val);
        if(!r && !l)
            ret.push_back(now);
        else if(!r)
            dfs(l);
        else if(!l)
            dfs(r);
        else
        {
            dfs(r);
            dfs(l);
        }
        now = now_bak;
    }
};