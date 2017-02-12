/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        if(NULL == root)
            return;
        root->next = NULL;
        queue<TreeLinkNode *> que;
        que.push(root);
        while(!que.empty())
        {
            int len = que.size();
            TreeLinkNode *pre = que.front();
            que.pop();
            if(pre->left)
                que.push(pre->left);
            if(pre->right)
                que.push(pre->right);
            for(int i = 1; i < len; i++)
            {
                TreeLinkNode *t = que.front();
                que.pop();
                pre->next = t;
                pre = t;
                if(pre->left)
                    que.push(pre->left);
                if(pre->right)
                    que.push(pre->right);
            }
            pre->next = NULL;
        }
    }
};