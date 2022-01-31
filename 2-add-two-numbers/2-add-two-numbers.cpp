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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int c=0;
        ListNode* h=NULL;
        ListNode* t=NULL;
        
        while(l1||l2)
        {
            //cout<<"here"<<endl;
            int s=c;
            if(l1)
            {
                s+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                s+=l2->val;
                l2=l2->next;
            }
            
            ListNode* n=new ListNode(s%10);
            c=s/10;
            if(!h)
            {
                h=n;
                t=n;
            }
            else
            {
                t->next=n;
                t=t->next;
            }
            
        }
        
        if(c)
        {
            ListNode* n=new ListNode(1);
            t->next=n;
            t=t->next;
        }
        
        return h;
        
    }
};