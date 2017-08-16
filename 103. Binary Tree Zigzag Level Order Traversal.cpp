/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//跟上一题相比加了一个反序
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode *> que;
        if(root)
            que.push(root);
        bool rev = false;
        while (!que.empty()) {
            int len = que.size();
            vector<int> a;
            for(int i = 0; i < len; i++) {
                TreeNode *node = que.front();
                que.pop();
                a.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            if(rev) {
                for(int i = 0, j = a.size() - 1; i < j; i++, j--)
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            ret.push_back(a);
            rev = !rev;
        }
        
        return ret;    
    }
};