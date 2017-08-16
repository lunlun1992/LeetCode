/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//如何递归产生二叉搜索树？每次都返回一个向量，里面包含了所有长度为n的树。
class Solution {
public:
    vector<TreeNode*> dfs(int b, int e)
    {
        vector<TreeNode *> ret;
        if (b > e) {
            ret.push_back(NULL);
        } else if (b == e) {
            ret.push_back(new TreeNode(b));
        } else {
            for (int i = b; i <= e; i++) {
                vector<TreeNode *> l = dfs(b, i - 1);
                vector<TreeNode *> r = dfs(i + 1, e);
                for (int u = 0; u < l.size(); u++) {
                    for (int v = 0; v < r.size(); v++) {
                        TreeNode *root = new TreeNode(i);
                        root->left = l[u];
                        root->right = r[v];
                        ret.push_back(root);
                    }
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n == 0)
            return ret;
        return dfs(1, n);
    }
};