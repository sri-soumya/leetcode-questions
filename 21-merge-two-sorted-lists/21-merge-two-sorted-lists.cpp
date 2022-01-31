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
        
        ListNode* l1,*l2,*res;
        
        if(list1->val<list2->val)
        {
            res=list1;
            l1=list1;
            l2=list2;
        }
        
        else
        {
            res=list2;
            l1=list2;
            l2=list1;
        }
        
        while(l1&&l2)
        {
            ListNode* t=NULL;
            while(l1&&l1->val<=l2->val)
            {
                t=l1;
                l1=l1->next;
            }
            
            t->next=l2;
            t=l1;
            l1=l2;
            l2=t;
        }
        
        return res;
    }
};