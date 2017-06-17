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
    void reverseListUtil(ListNode **head, ListNode *curr, ListNode * prev)
    {
            if (!curr)
                return;
            reverseListUtil(head, curr->next, curr);
            if (!curr->next)
                *head = curr;
            curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) 
    {
        if (!head)
            return NULL;
        if (!(head->next))
            return head;
        reverseListUtil(&head, head, NULL);
        return head;
    }
};
