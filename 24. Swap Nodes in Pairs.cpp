/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //插头法，每两个做一次插头
 //通过画图的方法来理清关系。
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode H(0);
        H.next = head;
        ListNode *before = &H;
        ListNode *end = before;
        
        while(true) {
            if (end->next && end->next->next) {
                end = end->next->next;
            } else {
                break;
            }
            
            before->next->next = end->next;
            end->next = before->next;
            before->next = end;
            before = end = end->next;
        }
        return H.next;
    }
};