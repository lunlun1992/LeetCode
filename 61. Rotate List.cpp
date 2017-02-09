/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//快慢指针，虚节点，插头法
//注意要让k在0-len-1范围内
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
        int len = 0;
        ListNode *aa = head;
        while(aa)
        {
            len++;
            aa = aa->next;
        }
        k %= len;
        
        ListNode H(0);
        ListNode *h = &H;
        ListNode *fast = h;
        ListNode *slow = h;
        h->next = head;
        for(int i = 0; i < k; i++)
            fast = fast->next;
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *node = slow->next;
        for(int i = 0; i < k; i++)
        {
            slow->next = node->next;
            node->next = h->next;
            h->next = node;
            h = node;
            node = slow->next;
        }
        
        return H.next;
    }
};