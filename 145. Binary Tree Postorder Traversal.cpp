/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//思想和前面的统一起来
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        TreeNode *node = root;
        stack<TreeNode *> st;
        unordered_set<TreeNode *> hasright;
        while(node || !st.empty())
        {
            if(node)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                node = st.top();
                if(hasright.count(node))
                {
                    ret.push_back(node->val);
                    st.pop();
                    node = NULL;
                }
                else
                {
                    hasright.insert(node);
                    node = node->right;
                }
            }
        }
        return ret;
    }
};