/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
//把random节点接在每一个源节点后面，然后就方便了额。
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(NULL == head)
            return NULL;
        RandomListNode *node = head;
        while(node)
        {
            RandomListNode *copy = new RandomListNode(node->label);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        
        
        node = head;
        while(node)
        {
            RandomListNode *copy = node->next;
            if(node->random)
                copy->random = node->random->next;
            node = node->next->next;
        }
        
        RandomListNode *orinode = head;
        RandomListNode *newnode = head->next;
        RandomListNode *ret = head->next;
        while(1)
        {
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