/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return head;
        
        Node* nh=NULL;
        Node* nt=NULL;
        Node* t=head;
        while(t)
        {
            Node* nn=new Node(t->val);
            Node* tt=t;
            
            nn->next=t->next;
            t->next=nn;
            t=nn->next;
        }
        
        t=head;
        
        while(t)
        {
            t->next->random=(t->random)?t->random->next:NULL;
            t=(t->next)?t->next->next:NULL;
        }
        
        t=head;
        
        while(t)
        {
            Node* tt=t->next;
            t->next=tt->next;
            if(!nh)
            {
                nh=tt;
                nt=tt;
            }
            else
            {
                nt->next=tt;
                nt=nt->next;
            }
            
            t=t->next;
        }
        
        return nh;
    }
};