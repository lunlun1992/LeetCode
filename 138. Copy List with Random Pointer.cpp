/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head)
            return NULL;
        //1. 把random节点接在每一个源节点后面。
        RandomListNode *node = head;
        while (node) {
            RandomListNode *copy = new RandomListNode(node->label);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        
        //2. 把原节点的random节点赋值给copy的节点。
        node = head;
        while (node) {
            RandomListNode *copy = node->next;
            if (node->random)
                copy->random = node->random->next;
            node = node->next->next;
        }
        
        //3. 把random节点串起来
        RandomListNode *orinode = head;
        RandomListNode *newnode = head->next;
        RandomListNode *ret = head->next;
        for (;;) {
            orinode->next = orinode->next->next;
            orinode = orinode->next;
            if(newnode->next == NULL)
                break;
            newnode->next = newnode->next->next;
            newnode = newnode->next;
        }
        
        return ret;
    }
};