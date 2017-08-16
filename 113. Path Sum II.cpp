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
    vector<vector<int>> ret;
    vector<int> arr;
    void travel(TreeNode *node, int sum) {
        if (NULL == node && sum == 0) {
            ret.push_back(arr);
            return;
        } else if (NULL == node && sum != 0) {
            return;
        }

        if (node->left) {
            arr.push_back(node->val);
            travel(node->left, sum - node->val);
            arr.pop_back();
        }
        if (node->right) {
            arr.push_back(node->val);
            travel(node->right, sum - node->val);
            arr.pop_back();
        }
        
        if (!node->right && !node->left){
            arr.push_back(node->val);
            travel(node->left, sum - node->val);
            arr.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return ret;
        travel(root, sum);
        return ret;
    }
};