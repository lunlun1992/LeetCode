/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //快慢指针法，确定倒数第n个
 //删除节点的时候需要一个辅助节点。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode H(0);
        H.next = head;
        ListNode *fast = &H;
        ListNode *slow = &H;
        while(n) {
            fast = fast->next;
            --n;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return H.next;
    }
};