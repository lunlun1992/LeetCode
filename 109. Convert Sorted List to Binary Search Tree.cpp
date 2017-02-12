/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* build(ListNode *b, ListNode *e)
    {
        if(b == e)
            return NULL;
        ListNode *slow = b;
        ListNode *fast = b;
        while(fast != e && fast->next != e)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *r = new TreeNode(slow->val);
        r->left = build(b, slow);
        r->right = build(slow->next, e);
        return r;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        return build(head, NULL);
    }
};