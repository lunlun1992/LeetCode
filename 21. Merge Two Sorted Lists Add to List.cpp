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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode H(0);
        ListNode *c = &H;
        while(l1 || l2)
        {
            int v1 = l1 ? l1->val : INT_MAX;
            int v2 = l2 ? l2->val : INT_MAX;
            if(v1 < v2)
            {
                c->next = l1;
                c = l1;
                l1 = l1->next;
            }
            else
            {
                c->next = l2;
                c = l2;
                l2 = l2->next;
            }
        }
        return H.next;
    }
};