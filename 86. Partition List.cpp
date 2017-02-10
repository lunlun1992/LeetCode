/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//在h之前都是比较小的数
//在h之后的数都没有经过比较，通过before指针遍历进行交换
class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if(!head)
            return NULL;
        ListNode H(0);
        ListNode *h = &H;
        h->next = head;
        ListNode *node = head;
        ListNode *before = h;
        
        while(before->next)
        {
            node = before->next;
            if(node->val < x)
            {
                if(before == h)
                    before = h = node;
                else
                {
                    before->next = node->next;
                    node->next = h->next;
                    h->next = node;
                    h = node;
                }
            }
            else
                before = node;
        }
        
        return H.next;
    }
};