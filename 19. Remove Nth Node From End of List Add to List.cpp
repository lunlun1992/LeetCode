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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL)
            return NULL;
        ListNode H(0);
        H.next = head;
        
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *beforeslow = &H;
        while(n--)
        {
            fast = fast->next;
        }
        while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
            beforeslow = beforeslow->next;
        }
        
        beforeslow->next = beforeslow->next->next;
        
        
        return H.next;
    }
};