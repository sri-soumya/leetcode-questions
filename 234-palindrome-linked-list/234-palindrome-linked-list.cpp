/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head)
    {
        
        if(!head)
            return head;
        
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* ne=cur->next;
        
        while(cur)
        {
            ne=cur->next;
            cur->next=prev;
            prev=cur;
            cur=ne;
        }
        
        return prev;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* t=head;
        
        while(fast&&fast->next)
        {
            t=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        t->next=NULL;
        
        ListNode* h2=reverse(slow);
        
        while(head&&h2)
        {
            if(head->val!=h2->val)
                return false;
            head=head->next;
            h2=h2->next;
        }
        
        return true;
    }
};