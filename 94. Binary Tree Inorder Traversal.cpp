//先左子树，就要将根压栈，到底后，将根弹出，输出，再将算法利用于右子树即可
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while(!st.empty() || node)
        {
            while(node)
            {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            ret.push_back(node->val);
            node = node->right;
        }
        return ret;
    }
};