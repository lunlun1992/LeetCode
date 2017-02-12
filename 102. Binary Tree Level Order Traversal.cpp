/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//队列的长度就是其本层的数量
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        queue<TreeNode *> que;
        if(root)
            que.push(root);
        while(!que.empty())
        {
            int len = que.size();
            vector<int> a;
            for(int i = 0; i < len; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                a.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
                
            }
            ret.push_back(a);
        }
        
        return ret;
    }
};