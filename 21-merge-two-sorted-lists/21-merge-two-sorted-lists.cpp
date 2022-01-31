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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1&&!list2)
            return list1;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        ListNode* h=NULL;
        ListNode* t=NULL;
        
        while(list1&&list2)
        {
            //cout<<list1->val<<" "<<list2->val<<" ";
            if(list1->val<list2->val)
            {
                //cout<<"l1 "<<list1->val<<endl;
                if(!h)
                {
                    h=list1;
                    t=list1;
                }
                else
                {
                    t->next=list1;
                    t=t->next;
                }
                list1=list1->next;
                t->next=NULL;
            }
            
            else
            {
                //cout<<"l2 "<<list2->val<<endl;
                
                if(!h)
                {
                    h=list2;
                    t=list2;
                }
                else
                {
                    t->next=list2;
                    t=t->next;
                }
                list2=list2->next;
                t->next=NULL;
            }
            
        }
        
        if(list1)
            t->next=list1;
        if(list2)
            t->next=list2;
        
        return h;
            
        
    }
};