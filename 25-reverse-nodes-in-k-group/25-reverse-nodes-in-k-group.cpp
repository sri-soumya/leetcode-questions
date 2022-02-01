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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int c=1;
        ListNode* h=head;
        ListNode* t=head;
        ListNode* pt=NULL;
        
        //return reverse(head);
        
        while(t)
        {
            if(c<k)
            {
                //pt=t;
                t=t->next;
                c++;
            }   
            else
            {
                //cout<<t->val<<endl;
                c=1;
                ListNode* tt=t->next;
                t->next=NULL;
                if(pt)
                    pt->next=NULL;
                ListNode* nh=reverse(h);
                if(h==head)
                    head=nh;
                else
                    pt->next=nh;
                h->next=tt;
                
                pt=h;
                t=h->next;
                h=h->next;
            }
                
        }
        
        return head;
        
    }
};