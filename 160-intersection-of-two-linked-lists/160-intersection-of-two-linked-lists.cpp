/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* t1=headA;
        ListNode* t2=headB;
        
        while(t1!=t2)
        {
            t1=(t1)?t1->next:headB;
            t2=(t2)?t2->next:headA;
            
        }
        
        return t1;
    }
};