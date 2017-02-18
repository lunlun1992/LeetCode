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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode H(INT_MIN);
        for(ListNode *node = head; node;)
        {
            ListNode *h = &H;
            while(h->next && h->next->val < node->val)
                h = h->next;
            ListNode *temp = node->next;
            node->next = h->next;
            h->next = node;
            node = temp;
        }
        return H.next;
    }
};