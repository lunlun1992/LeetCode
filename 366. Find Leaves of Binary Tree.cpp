/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//寻找高度的算法
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root)
    {
        height(root);
        return ret;
    }
private:
    vector<vector<int>> ret;
    int height(TreeNode *r)
    {
        if(!r)
            return -1;
        int now = 1 + max(height(r->left), height(r->right));
        if(ret.size() == now)
            ret.push_back(vector<int>({r->val}));
        else
            ret[now].push_back(r->val);
        return now;
    }
};