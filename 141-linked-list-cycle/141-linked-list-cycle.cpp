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
    bool hasCycle(ListNode *head) {
        
        auto f=head,s=head;
        
        while(f&&f->next)
        {
            s=s->next;
            f=f->next->next;
            if(f==s)
                break;
        }
        
        if(!f||!f->next)
            return 0;
        
        return 1;
        
    }
};