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
//If one of the subtree sum is negative, discard it.
class Solution {
public:
    
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int lmax = max(0, dfs(root->left));
        int rmax = max(0, dfs(root->right));
        maxi = max(lmax + rmax + root->val, maxi);
        return max(lmax, rmax) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        dfs(root);
        return maxi;
    }
private:
    int maxi;
};