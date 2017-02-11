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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode H(0);
        ListNode *h = &H;
        h->next = head;
        if(m == n)
            return head;
        int len = n - m;
        
        while(m-- != 1)
            h = h->next;
        ListNode *node = h->next->next;
        ListNode *before = h->next;
        while(len--)
        {
            before->next = node->next;
            node->next = h->next;
            h->next = node;
            node = before->next;
        }
        return H.next;
    }
};