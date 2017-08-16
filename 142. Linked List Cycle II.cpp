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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && slow) {
            fast = fast->next;
            if (!fast)
                return NULL;
            fast = fast->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode *node = head;
                while (node != slow) {
                    node = node->next;
                    slow = slow->next;
                }
                return node;
            }
        }
        return NULL;
    }
};