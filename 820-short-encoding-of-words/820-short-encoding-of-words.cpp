class Node
{
    Node* a[26]={NULL};
    bool f=false;
    
    public:
    bool containsNode(int x)
    {
        return a[x]!=NULL;
    }
    
    void putNode(int x,Node *t)
    {
        a[x]=t;
    }
    
    Node* getNode(int x)
    {
        return a[x];
    }
    
    void putEnd()
    {
        f=true;
    }
    
    bool isEnd()
    {
        return f;
    }
    
    
};

class Trie {
    
Node* root;
public:
    Trie() {
        
        root=new Node();
        
    }
    
    int insert(string s) {
        
        int n=s.length(),a=0;
        Node* t=root;
        for(int i=0;i<n;i++)
        {
            if(!t->containsNode(s[i]-'a'))
            {
                t->putNode(s[i]-'a',new Node());
                if(!a)
                    a=n+1;
            }
            t=t->getNode(s[i]-'a');
        }
        
        t->putEnd();
            
        return a;
    }
    
    bool search(string s) {
     
        int n=s.length();
        Node* t=root;
        
        for(int i=0;i<n;i++)
        {
            if(!t->containsNode(s[i]-'a'))
                return false;
            t=t->getNode(s[i]-'a');
        }
        
        return t->isEnd();
        
    }
    
    bool startsWith(string s) {
        
        int n=s.length();
        Node* t=root;
        
        for(int i=0;i<n;i++)
        {
            if(!t->containsNode(s[i]-'a'))
                return false;
            t=t->getNode(s[i]-'a');
        }
        
        return true;
        
    }
    
};

class Solution {
public:
    
    static bool compare(string a,string b)
    {
        return a.length()>b.length();
    }
    
    int minimumLengthEncoding(vector<string>& a) {
        
        Trie ob;
        
        int s=0,n=a.size();
        
        for(int i=0;i<n;i++)
        {
            reverse(a[i].begin(),a[i].end());
        }
        
        sort(a.begin(),a.end(),compare);
        for(int i=0;i<n;i++)
        {
            s+=ob.insert(a[i]);
        }
        return s;
        
    }
};