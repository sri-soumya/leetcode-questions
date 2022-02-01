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
        
        map<ListNode*,int> x;
        
        while(headA)
        {
            x[headA]++;
            headA=headA->next;
        }
        
        while(headB)
        {
            if(x.count(headB))
                return headB;
            headB=headB->next;
        }
        
        return NULL;
        
    }
};