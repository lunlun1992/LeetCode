/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//利用一个优先队列即可
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int len = lists.size();
        ListNode H(0);
        ListNode *h = &H;
        for(int i = 0; i < len; i++)
            if(lists[i])
                que.push(lists[i]);
        while(!que.empty())
        {
            ListNode *l = que.top();
            que.pop();
            h->next = l;
            h = l;
            if(l->next)
                que.push(l->next);
        }
        return H.next;
    }
private:
    struct Cmp
    {
        bool operator()(ListNode *l1, ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };
    priority_queue<ListNode *, vector<ListNode *>, Cmp> que;
};