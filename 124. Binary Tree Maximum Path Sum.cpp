/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//分两条支线，第一条是穿越本根节点链接两个子树的路线，用ret衡量。
//另外一条是只有一半，这样上一层的节点可以利用本节点的路线，用return返回。
class Solution {
public:
    int ret;
    int dfs(TreeNode *node)
    {
        if(NULL == node)
            return 0;
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        ret = max(ret, left + right + node->val);
        return max(left, right) + node->val;
    }
    int maxPathSum(TreeNode* root) 
    {
        ret = INT_MIN;
        ret = max(dfs(root), ret);
        return ret;
    }
};