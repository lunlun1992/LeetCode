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
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<TreeNode *> que;
        vector<int> ret;
        if(root)
            que.push(root);
        while(!que.empty())
        {
            int len = que.size();
            for(int i = 0; i < len - 1; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            TreeNode *node = que.front();
            que.pop();
            ret.push_back(node->val);
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
        return ret;
    }
};