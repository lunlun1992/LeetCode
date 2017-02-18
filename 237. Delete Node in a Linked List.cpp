//删除一个节点。只需要把下一个节点的参数完全复制到这个节点即可。
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
    void deleteNode(ListNode* node)
    {
        ListNode *n = node->next;
        node->val = n->val;
        node->next = n->next;

    }
};