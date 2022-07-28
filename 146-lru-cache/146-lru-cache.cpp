#define ff first
#define ss second
class node{
    public:
    pair<int,int> data;
    node* next;
    node *prev;
    
    node(int key,int value)
    {
        data={key,value};
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:
    
    node* head,*tail;
    int cap;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
        
        cap=capacity;
        head=new node(0,0);
        tail=new node(0,0);
        
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        
        if(!mp.count(key))
            return -1;
        
        int x=mp[key]->data.ss;
        remove(key);
        insert(key,x);
        
        return x;
    }
    
    void put(int key, int value) {
        
        if(mp.size()<cap&&!mp.count(key))
            insert(key,value);
        else if(mp.count(key))
        {
            remove(key);
            insert(key,value);
        }
        else
        {
            remove(tail->prev->data.ff);
            insert(key,value);
        }
    }
    
    void remove(int key)
    {
        node* t=mp[key];
        t->prev->next=t->next;
        t->next->prev=t->prev;
        
        mp.erase(key);
    }
    
    void insert(int key,int value)
    {
        node *t=new node(key,value);
        t->next=head->next;
        t->prev=head;
        head->next=t;
        t->next->prev=t;
        mp[key]=t; 
        
        node* temp=head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */