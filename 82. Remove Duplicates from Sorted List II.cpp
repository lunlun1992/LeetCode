/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// h->lastnode->node
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        ListNode H(0);
        ListNode *h = &H;
        h->next = head;
        ListNode *node = head->next;
        ListNode *lastnode = head;
        bool firstnode = true;
        
        while(node) {
            if (lastnode->val == node->val) {
                firstnode = false;
            } else if (firstnode) {
                h->next = lastnode;
                h = lastnode;
                lastnode = node;
                firstnode = true;
            } else {
                firstnode = true;
                lastnode = node;
            }
            node = node->next;
        }
        
        if (firstnode) {
            h->next = lastnode;
            h = lastnode;
        }
        h->next = NULL;
        return H.next;
    }
};