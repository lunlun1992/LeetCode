/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//中序遍历
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) 
    {
        if(k == 0)
            return {};
        TreeNode *node = root;
        stack<TreeNode *> st;
        deque<int> dq;
        while(!st.empty() || node)
        {
            while(node)
            {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            if(dq.size() < k)
                dq.push_back(node->val);
            else
            {
                if(abs(dq.front() - target) >= abs(node->val - target))
                {
                    dq.pop_front();
                    dq.push_back(node->val);
                }
                else
                    break;
            }
            node = node->right;
        }
        vector<int> ret(dq.begin(), dq.end());
        return ret;
        
    }
};