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
    int dfs(TreeNode *r) {
        if(!r)
            return 0;
        if(m.count(r)) {
            return m[r];
        } else {
            int val = dfs(r->left) + dfs(r->right) + 1;
            m[r] = val;
            return val;
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            m[NULL] = 0;
            return 0;
        }
        int left = m.count(root->left) ? m[root->left] : dfs(root->left);
        if (left + 1 == k)
            return root->val;
        else if (left + 1 < k)
            return kthSmallest(root->right, k - left - 1);
        else
            return kthSmallest(root->left, k);
    }
private:
    unordered_map<TreeNode *, int> m;
};