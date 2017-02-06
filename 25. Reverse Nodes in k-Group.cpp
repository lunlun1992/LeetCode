/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //插入头部法
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k == 1 || !head)
            return head;
        ListNode H(0);
        H.next = head;
        ListNode *before = &H;
        ListNode *end = before;
        
        while(1)
        {
            for(int i = 0; i < k; i++)
                if(end);
                    end = end->next;
            if(!end)
                break;
            ListNode *nextone = end->next;
            ListNode *bnode = before->next;
            ListNode *node = before->next->next;
            while(node != nextone)
            {
                bnode->next = node->next;
                node->next = before->next;
                before->next = node;
                node = bnode->next;
            }
            before = bnode;
            end = bnode;
        }
        return H.next;
    }
};