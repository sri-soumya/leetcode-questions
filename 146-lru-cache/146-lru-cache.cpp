class node
{
    public:
    pair<int,int> data;
    node* next;
    node* prev;
    
    node(int k,int d)
    {
        data={k,d};
        next=NULL;
        prev=NULL;
    }
    
};

class LRUCache {
public:
    map<int,node*> x;
    node* head;
    node* tail;
    int c;
    LRUCache(int capacity) {
        c=capacity;
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        
    }
    
    void remove(node* n)
    {
        node* t=tail;
        
        n->prev->next=n->next;
        n->next->prev=n->prev;
        t=head;
        
        x.erase(n->data.first);
    }
    
    void insert(int key,int value)
    {
        
        node* n=new node(key,value);
        
        n->next=head->next;
        n->prev=head;
        head->next=n;
        n->next->prev=n;
        node* t=tail;
        x[key]=n;
        
    }
    
    int get(int key) {
        
        if(!x.count(key))
            return -1;
        node* t=x[key];
        
        remove(t);
        insert(t->data.first,t->data.second);
        
        return t->data.second;
    }
    
    void put(int key, int value) {
        
        if(!x.count(key))
        {
            if(x.size()>=c)
            {
                
                remove(tail->prev);
                insert(key,value);
                
            }
            else
            {
                
                insert(key,value);
                
            }
            
        }
        else
        {
            node* t=x[key];
            remove(t);
            insert(key,value);
            
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */