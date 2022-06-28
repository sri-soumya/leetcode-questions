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
    ListNode *detectCycle(ListNode *head) {
        
        auto f=head,s=head;
        
        while(f&&f->next)
        {
            s=s->next;
            f=f->next->next;
            if(s==f)
                break;
        }
        
        if(!f||!f->next)
            return 0;
        f=head;
        while(f!=s)
        {
            s=s->next;
            f=f->next;
            
        }
        
        return f;
    }
};