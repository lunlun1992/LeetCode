/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//最好使用||，原因是代码会更简单。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode H(0);
        int adder = 0;
        ListNode *h = &H;
        while(l1 || l2 || adder) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + adder;
            h->next = new ListNode(sum);
            h = h->next;
            adder = h->val / 10;
            h->val %= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return H.next;
    }
};