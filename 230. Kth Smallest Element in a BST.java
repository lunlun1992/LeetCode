//分治法，先统计左子树的节点数，确定在哪里。然后接着递归搜索，有点像select算法。
//无论如何，先写出来再说，不要犹豫会不会更好。
public static int dfs(TreeNode node)
{
    if(null == node)
        return 0;
    else
        return dfs(node.left) + dfs(node.right) + 1;
}
public static int kthSmallest(TreeNode root, int k)
{
    if(null == root)
        return 0;
    int nleft = dfs(root.left);
    if(nleft + 1 == k)
        return root.val;
    else if(nleft + 1 < k)
        return kthSmallest(root.right, k - nleft - 1);
    else
        return kthSmallest(root.left, k);
}


//记忆化搜索版本
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
    int dfs(TreeNode *r)
    {
        if(!r)
            return 0;
        if(m.count(r))
            return m[r];
        else
        {
            int val = dfs(r->left) + dfs(r->right) + 1;
            m[r] = val;
            return val;
        }
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        if(!root)
        {
            m[NULL] = 0;
            return 0;
        }
        int left = m.count(root->left) ? m[root->left] : dfs(root->left);
        if(left + 1 == k)
            return root->val;
        else if(left + 1 < k)
            return kthSmallest(root->right, k - left - 1);
        else
            return kthSmallest(root->left, k);
    }
private:
    unordered_map<TreeNode *, int> m;
};