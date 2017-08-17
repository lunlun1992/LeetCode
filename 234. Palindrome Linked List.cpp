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
    ListNode *reverseList(ListNode *head) {
        ListNode *H = new ListNode(0);
        H->next = head;
        ListNode *node = head;
        while (node->next != NULL) {
            ListNode *tmp = node->next;
            node->next = node->next->next;
            tmp->next = H->next;
            H->next = tmp;
        }
        return H->next;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || head->next == NULL)
            return true;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL) {
            fast = fast->next;
            if (!fast)
                break;
            fast = fast->next;
            if (!fast)
                break;
            slow = slow->next;
        }
        
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *rev = reverseList(mid);
        
        slow = head;
        while (rev) {
            if (slow->val != rev->val)
                return false;
            slow = slow->next;
            rev = rev->next;
        }
        return true;
    }
};