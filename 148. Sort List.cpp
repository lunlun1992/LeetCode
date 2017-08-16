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
    ListNode* findmid(ListNode *h, ListNode *e) {
        ListNode *n1 = h;
        ListNode *n2 = h;
        while (n2 != e && n2->next != e) {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        return n1;
    }

    ListNode* merge(ListNode *l, ListNode *lend, ListNode *r, ListNode *rend) {
        ListNode *H = new ListNode(0);
        ListNode *n = H;
        while (l != lend && r != rend) {
            if (l->val < r->val) {
                n->next = l;
                n = n->next;
                l = l->next;
            } else {
                n->next = r;
                n = n->next;
                r = r->next;
            }
        }
        if (l == lend) {
            n->next = r;
            while (n->next != rend)
                n = n->next;
        } else if (r == rend) {
            n->next = l;
            while (n->next != lend)
                n = n->next;
        }
        n->next = rend;
        return H->next;
    }

    ListNode* sort(ListNode *h, ListNode *e)
    {
        if (h == NULL || h->next == e)
            return h;
        ListNode *mid = findmid(h, e);
        ListNode *left = sort(h, mid);
        ListNode *right = sort(mid, e);
        return merge(left, mid, right, e);
    }
    ListNode* sortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *mid = findmid(head, NULL);
        ListNode *left = sort(head, mid);
        ListNode *right = sort(mid, NULL);
        return merge(left, mid, right, NULL);
    }
};