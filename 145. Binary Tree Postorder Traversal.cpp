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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        unordered_set<TreeNode*> hasvisit;
        TreeNode *node = root;
        
        while (!st.empty() || node) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            TreeNode *tmp = st.top();
            if (hasvisit.count(st.top())) {
                ret.push_back(tmp->val);
                st.pop();
            } else {
                hasvisit.insert(tmp);
                node = tmp->right;
            }
        }
        return ret;
    }
};