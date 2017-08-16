/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//从中间翻转，然后继续操作之。
class Solution {
public:
    void reorderList(ListNode* head)  {
        if (!head || !head->next)
            return;
        
        //找到中点
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *node = head;
        while(node->next != slow)
            node = node->next;

        //翻转后半部分
        ListNode *second = slow;
        ListNode *back = node;
        while (second->next) {
            ListNode *temp = second->next;
            second->next = temp->next;
            temp->next = back->next;
            back->next = temp;
        }
        second = back->next;
        back->next = NULL;
        slow = head;
        
        //合并
        ListNode *H = new ListNode(0);
        while(slow)
        {
            ListNode *secondn = second->next;
            ListNode *slown = slow->next;
            H->next = slow;
            slow->next = second;
            H = second;
            slow = slown;
            second = secondn;
        }
        if(second)
            H->next = second;
        
    }
};