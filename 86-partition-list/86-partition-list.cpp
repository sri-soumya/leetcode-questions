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
    
    ListNode* connect(ListNode* &x,ListNode* &h,ListNode* &t)
    {
        if(!h&&!t)
        {
            h=x;
            t=x;
        }
        
        else
        {
            t->next=x;
            t=t->next;
        }
        
        ListNode* temp=x->next;
        x->next=NULL;
        return temp;
    }
    
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* t=head,*lh=NULL,*lt=NULL,*rh=NULL,*rt=NULL;
        
        while(t)
        {
            if(t->val<x)
            {
                t=connect(t,lh,lt);
            }
            else
                t=connect(t,rh,rt);
        }
        
        if(lt)
            lt->next=rh;
        
        if(lh)
            return lh;
        
        return rh;
    }
};