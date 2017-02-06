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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode H(0);
        H.next = head;
        ListNode *before = &H;
        ListNode *end = before;
        while(1)
        {
            end = end->next;
            if(end && end->next)//这里容易出错，注意两个节点都要是非空的才继续。
                end = end->next;
            else
                break;
            before->next->next = end->next;
            end->next = before->next;
            before->next = end;
            
            before = end->next;
            end = end->next;
        }
        return H.next;
    }
};