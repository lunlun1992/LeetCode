/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//这题也需要使用层次遍历法
//同时还需要usinghahah
class Solution {
public:
    using P = pair<TreeNode *, int>;
    vector<vector<int>> verticalOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        map<int, vector<int>> m;
        
        queue<P> que;
        que.push(P(root, 0));
        while(!que.empty())
        {
            int len = que.size();
            for(int i = 0; i < len; i++)
            {
                P now = que.front();
                que.pop();
                
                TreeNode *node = now.first;
                int x = now.second;
                if(!node)
                    continue;
                m[x].push_back(node->val);
                que.push(P(node->left, x - 1));
                que.push(P(node->right, x + 1));
            }
        }
        for(auto it : m)
            ret.push_back(it.second);
        return ret;
    }
};