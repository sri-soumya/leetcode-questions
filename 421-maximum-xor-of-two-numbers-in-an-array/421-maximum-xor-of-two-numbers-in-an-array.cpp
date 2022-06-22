class Node
{
    Node* a[2];
    
    public:
    
    bool containsNode(int x)
    {
        return a[x]!=NULL;
    }
    
    void addNode(int x,Node* t)
    {
        a[x]=t;
    }
    
    Node* nextNode(int x)
    {
        return a[x];
    }
};


class Trie
{
    Node* root;
    
    public:
    
    Trie()
    {
        root=new Node();
    }
    
    void insert(int a)
    {
        Node* t=root;
        for(int i=31;i>=0;i--)
        {
            int x=(a>>i)&1;
            if(!t->containsNode(x))
                t->addNode(x,new Node());
            t=t->nextNode(x);
        }
        
    }
    
    int maxXOR(int a)
    {
        Node *t=root;
        int n=0;
        for(int i=31;i>=0;i--)
        {
            int x=!((a>>i)&1);
            if(!t->containsNode(x))
            {
                t=t->nextNode(!x);
            }
            else
            {
                n=n|(1<<i);
                t=t->nextNode(x);
            }
        }
        
        return n;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        
        int n=a.size();
        int ans=INT_MIN;
        Trie ob;
        for(int i=0;i<n;i++)
        {
            ob.insert(a[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,ob.maxXOR(a[i]));
        }
        
        return ans;
        
    }
};