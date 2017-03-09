//设计一个返回类来处理这件事情
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
    int largestBSTSubtree(TreeNode* root) 
    {
        dfs(root);
        return ans;
    }
private:
    struct Ret
    {
        int n;
        int l;
        int r;
        Ret(int _n, int _l, int _r) : n(_n), l(_l), r(_r){};
    };
    int ans = 0;
    Ret dfs(TreeNode *r)
    {
        if(!r)
            return Ret(0, INT_MAX, INT_MIN);
        Ret left = dfs(r->left);
        Ret right = dfs(r->right);
        if(left.n == -1 || right.n == -1 || r->val <= left.r || r->val >= right.l)
            return Ret(-1, 0, 0);
        int now = left.n + right.n + 1;
        ans = max(now, ans);
        return Ret(now, min(left.l, r->val), max(right.r, r->val));
    }
    
};