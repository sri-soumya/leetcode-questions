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
    ListNode* reverseBetween(ListNode* h, int l, int r) {
        
        ListNode* nh=h,*p=NULL;
        int c=r-l+1;
        l--;
        while(l--)
        {
            p=nh;
            nh=nh->next;
        }
        
        if(p)
            p->next=NULL;
        
        ListNode* t=nh;
        
        ListNode* prev=NULL,*cur=nh,*ne=NULL;
        
        while(cur&&c--)
        {
            ne=cur->next;
            cur->next=prev;
            prev=cur;
            cur=ne;
        }
        
        t->next=ne;
        
        if(p)
            p->next=prev;
        
        if(p)
            return h;
        
       return prev;
    }
};