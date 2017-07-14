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
    bool isPalindrome(ListNode *h, ListNode **H)
    {
        if (!h)
            return true;
        
        if (   !isPalindrome(h->next,H)
            || h->val != (*H)->val)
            return false;
        
        (*H)=(*H)->next;
        return true;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        return isPalindrome(head, &head);    
    }
};