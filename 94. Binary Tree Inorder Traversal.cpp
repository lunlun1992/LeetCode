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
//node就是要处理的节点，st对这个节点左到底，然后输出值，最后算法应用于右节点。
//如果右节点为空，则返回上一层，这个时候用栈即可。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode *node = root;
        
        while (!st.empty() || node) {
            while (node) {
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