/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode H(0);
        ListNode *h = &H;
        h->next = head;
        ListNode *node = head;
        while(node->next)
        {
            ListNode *temp = node->next;
            node->next = node->next->next;
            temp->next = h->next;
            h->next = temp;
        }
        return h->next;
    }
};