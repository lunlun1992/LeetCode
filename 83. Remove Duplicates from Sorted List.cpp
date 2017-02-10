/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//和上题一样的思路
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode H(0);
        ListNode *h = &H;
        h->next = head;
        ListNode *node = head;
        ListNode *lastnode = head;
        
        while(node)
        {
            if(lastnode->val == node->val)
                node = node->next;
            else
            {
                h->next = lastnode;
                h = lastnode;
                lastnode = node;
                node = node->next;
            }
        }
        
        if(lastnode)
        {
            h->next = lastnode;
            h = lastnode;
        }
        h->next = NULL;
        return H.next;
    }
};