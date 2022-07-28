class MyStack {
public:
    
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        
        int n=q.size();
        
        for(int i=0;i<n-1;i++)
        {
            int x=q.front();
            q.pop();
            q.push(x);
        }
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        int n=q.size();
        
        for(int i=0;i<n-1;i++)
        {
            int x=q.front();
            q.pop();
            q.push(x);
        }
        int x=q.front();
        q.pop();
        q.push(x);
        return x;
    }
    
    bool empty() {
        
        return !q.size();
        
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