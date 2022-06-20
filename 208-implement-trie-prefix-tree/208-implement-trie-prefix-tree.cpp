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
    
    void insert(string s) {
        
        int n=s.length();
        Node* t=root;
        for(int i=0;i<n;i++)
        {
            if(!t->containsNode(s[i]-'a'))
                t->putNode(s[i]-'a',new Node());
            t=t->getNode(s[i]-'a');
        }
        
        t->putEnd();
            
        
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */