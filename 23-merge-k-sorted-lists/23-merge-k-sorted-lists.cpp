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
    
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(!a&&!b)
            return NULL;
        if(!a)
            return b;
        
        if(!b)
            return a;
        
        ListNode* x,*y,*h;
        if(a->val<b->val)
        {
            h=a;
            x=a;
            y=b;
        }
        else
        {
            h=b;
            x=b;
            y=a;
        }
        while(x&&y)
        {
            ListNode* t=NULL;
            while(x&&x->val<=y->val)
            {
                t=x;
                x=x->next;
                
            }
            
            t->next=y;
            t=x;
            x=y;
            y=t;
            //swap(x,y);
        }
        
        return h;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(!lists.size())
            return NULL;
        if(lists.size()==1)
            return lists[0];
        ListNode* h=lists[0];
        for(int i=1;i<lists.size();i++)
            h=merge(h,lists[i]);
        
        // while(h)
        // {
        //     cout<<h->val<<" ";
        //     h=h->next;
        // }
        
        
        
        return h;
        
    }
};