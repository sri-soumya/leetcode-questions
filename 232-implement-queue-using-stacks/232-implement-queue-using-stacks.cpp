class MyQueue {
public:
    stack<int> *a,*b;
    
    MyQueue() {
        a=new stack<int>;
        b=new stack<int>;
        
    }
    
    void push(int x) {
       
        a->push(x);
    }
    
    int pop() {
        int x=0;
        if(!a->size()&&!b->size())
            return -1;
        if(b->size())
        {
            x=b->top();
            b->pop();
            
            return x;
        }
        
        int z=0;
        while(a->size())
        {
            b->push(a->top());
            a->pop();
        }
        
        x=b->top();
        b->pop();
        return x;
    }
    
    int peek() {
        int x=0;
        if(!a->size()&&!b->size())
            return -1;
        if(b->size())
        {
            x=b->top();
            
           
            return x;
        }
        
        int z=0;
        while(a->size())
        {
            b->push(a->top());
            a->pop();
        }
        
        x=b->top();
        
        return x;
        
    }
    
    bool empty() {
        return !a->size()&&!b->size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */