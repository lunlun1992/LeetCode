/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//默认方式，node和一个stack辅助共存
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode *> st;
        vector<int> ret;
        TreeNode *node = root;
        while(!st.empty() || node)
        {
            if(node)
            {
                ret.push_back(node->val);
                st.push(node);
                node = node->left;

            }
            else
            {
                node = st.top();
                st.pop();
                node = node->right;
            }
        }
        return ret;
    }
};