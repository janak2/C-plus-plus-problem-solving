/**
 *Q. Given a linked list, remove the nth node from the end of list and return its head. Do it in one pass.
 *
 *You stored all pointers but two is enough. One should be n steps ahead of another one and when the further one reaches null,
 *the previous one reaches nth from end.
 *
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> m;
        ListNode* c = new ListNode(0);
        c->next = head;
        m.push_back(c);
        ListNode* t = c->next;
        while(t!=NULL)
        {
            m.push_back(t);
            t = t->next;
        }
        int index = m.size() - n;
        m[index-1]->next = m[index]->next;
        return c->next;
    }
};
