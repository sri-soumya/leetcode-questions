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
    
    ListNode* reverse(ListNode* h)
    {
        ListNode *p=NULL,*c=h,*n=NULL;
        
        while(c)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(!head||!head->next)
            return true;
        
        ListNode *f=head->next,*s=head;
        
        while(f&&f->next)
        {
            s=s->next;
            f=f->next->next;
        }
        
        ListNode* t=s->next;
        s->next=NULL;
        ListNode* h=reverse(t);
        
        while(head&&h)
        {
            if(head->val!=h->val)
                return false;
            head=head->next;
            h=h->next;
        }
        
        return true;
    }
};