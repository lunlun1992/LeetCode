/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//遍历整棵树找到p、q节点
//然后在回溯的时候，如果某一分支返回值非空，则那个分支上一定有p或者q或者both，则继续向上返回。
//如果两个分支都非空，则这就是需要的节点。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left && right)
            return root;
        else if(left)
            return left;
        else if(right)
            return right;
        else
            return NULL;
    }
};