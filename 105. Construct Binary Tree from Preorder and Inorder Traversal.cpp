/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//先找到根节点，然后分别递归
class Solution {
public:
    
    TreeNode *build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie)
    {
        if(ps > pe)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int i = is;
        while(i <= ie && inorder[i] != preorder[ps])
            i++;
        root->left = build(preorder, ps + 1, ps + i - is, inorder, is, i - 1);
        root->right = build(preorder, pe - ie + i + 1, pe, inorder, i + 1, ie);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);    
    }
};