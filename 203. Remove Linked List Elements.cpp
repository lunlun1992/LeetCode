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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode H(0);
        H.next = head;
        ListNode *h = &H;
        while(h->next)
        {
            if(h->next->val == val)
                h->next = h->next->next;
            else
                h = h->next;
        }
        return H.next;
    }
};