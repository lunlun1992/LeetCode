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

    TreeNode *build(vector<int> &nums, int b, int e)
    {
        if(b > e)
            return NULL;
        int m = b + ((e - b) >> 1);
        TreeNode *node = new TreeNode (nums[m]);
        node->left = build(nums, b, m - 1);
        node->right = build(nums, m + 1, e);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};