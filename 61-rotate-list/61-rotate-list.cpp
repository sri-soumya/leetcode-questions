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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head||!k)
            return head;
        
        int n=0;
        ListNode* t=head;
        ListNode* tt=NULL;
        
        while(t)
        {
            n++;
            tt=t;
            t=t->next;
        }
        
        k%=n;
        n-=k;
        int c=1;
        
        t=head;
        
        if(!n)
            return head;
        
        while(c<n)
        {
            c++;
            t=t->next;    
        }
        
        tt->next=head;
        tt=t->next;
        t->next=NULL;
        
        return tt;
    }
};