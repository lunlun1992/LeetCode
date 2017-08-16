/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//lastnode里面存上一个节点，如果一直等于上一个节点则一直往下，
//否则，去除之。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode H(0);
        ListNode *h = &H;
        h->next = head;
        ListNode *node = head;
        ListNode *lastnode = head;
        
        while (node) {
            if (lastnode->val == node->val) {
                node = node->next;
            } else {
                h->next = lastnode;
                h = lastnode;
                lastnode = node;
                node = node->next;
            }
        }
        
        if (lastnode) {
            h->next = lastnode;
            h = lastnode;
        }
        h->next = NULL;
        return H.next;
    }
};