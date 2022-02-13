class MyStack {
public:
    queue<int> *a;
    queue<int> *b;
    int t=0;
    MyStack() {
        a=new queue<int>;
        b=new queue<int>;
    }
    
    void push(int x) {
        a->push(x);
        t=x;
    }
    
    int pop() {
        if(empty())
            return -1;
        int z=a->size();
        while(z>1)
        {
            int x=a->front();
            a->pop();
            a->push(x);
            z--;
        }
        int x=a->front();
        a->pop();
        return x;
    }
    
    int top() {
        if(empty())
            return -1;
        int z=a->size();
        while(z>1)
        {
            int x=a->front();
            a->pop();
            a->push(x);
            z--;
        }
        int x=a->front();
        a->pop();
        a->push(x);
        return x;
        
    }
    
    bool empty() {
        
        return a->size()==0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */