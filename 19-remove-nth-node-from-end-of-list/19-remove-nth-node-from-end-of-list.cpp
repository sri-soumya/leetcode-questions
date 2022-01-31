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
    
    pair<ListNode*,int> solve(ListNode* h,int n)
    {
        if(!h)
            return {h,0};
        
        pair<ListNode*,int> a=solve(h->next,n);
        h->next=a.first;
        if(a.second+1==n)
            h=h->next;
        
        return {h,a.second+1};
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //return solve(head,n).first;
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        for(int i=0;i<n;i++)
            fast=fast->next;
        
        if(!fast)
            return head->next;
            
        
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        
        slow->next=slow->next->next;
        
        return head;
        
    }
};