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
        
        vector<Node*> a;
        map<Node*,int> x;
        Node* t=head;
        int c=0;
        while(t)
        {
            Node* tt=new Node(t->val);
            a.push_back(tt);
            x[t]=c++;
            t=t->next;
        }
        
        a.push_back(NULL);
        t=head;
        for(int i=0;i<a.size()-1;i++)
        {
            a[i]->next=a[i+1];
            a[i]->random=(t->random)?a[x[t->random]]:NULL;
            t=t->next;
        }
        
        return a[0];
        
    }
};