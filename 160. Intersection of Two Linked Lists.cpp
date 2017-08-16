/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//有一种方法，是将其中一个链表头尾相连，按照找链表有没有圈的标准来找交点。
//第二种方法，直接判断链表长度，从短的那个节点开始，往后找，找到相等或者尾巴为止，返回即可。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode *node = headA;
        while (node) {
            len1++;
            node = node->next;
        }
        node = headB;
        while (node) {
            len2++;
            node = node->next;
        }
        
        if (len1 < len2) {
            int diff = len2 - len1;
            while (diff--)
                headB = headB->next;
        } else if (len1 > len2) {
            int diff = len1 - len2;
            while (diff--)
                headA = headA->next;
        }
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;

    }
};