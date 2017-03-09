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
    ListNode* plusOne(ListNode* head) 
    {
        ListNode *node = head;
        ListNode *lastone = NULL;
        while(node)
        {
            if(node->val != 9)
                lastone = node;
            node = node->next;
        }
        if(!lastone)
        {
            ListNode *newhead = new ListNode(1);
            newhead->next = head;
            node = head;
            while(node)
            {
                node->val = 0;
                node = node->next;
            }
            return newhead;
        }
        else
        {
            lastone->val++;
            lastone = lastone->next;
            while(lastone)
            {
                lastone->val = 0;
                lastone = lastone->next;
            }
            return head;
        }
            
    }
};