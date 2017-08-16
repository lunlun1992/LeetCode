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

    TreeNode *build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        if(is > ie)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);
        int i = is;
        while(i <= ie && inorder[i] != postorder[pe])
            i++;
        root->left = build(inorder, is, i - 1, postorder, ps, ps + i - 1 - is);
        root->right = build(inorder, i + 1, ie, postorder, ps + i - is, pe - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};