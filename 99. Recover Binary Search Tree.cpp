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
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev;
    
    void travel(TreeNode *root)
    {
        if(NULL == root)
            return;
        travel(root->left);
        
        if(prev->val >= root->val)
        {
            if(NULL == first)
                first = prev;
            if(NULL != first)//这里注意，有可能是相邻两个节点换了，所以要更新second
                second = root;
        }
        prev = root;
        travel(root->right);
    }
    
    void recoverTree(TreeNode* root) 
    {
        prev = new TreeNode(INT_MIN);
        travel(root);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        
        
    }
};