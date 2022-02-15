
class MinStack {
public:
    stack<long long> s;
    long long mini;
    MinStack() {
        //s=new vector<int>;
        mini=INT_MAX;
    }
    
    void push(long long val) {
        if(!s.size())
        {
            s.push(val);
            mini=val;
        }
        else if(val>mini)
            s.push(val);
        else
        {
            s.push(2*val-mini);
            mini=val;
        }
    }
    
    void pop() {
        if(s.top()>mini)
            s.pop();
        else
        {
            mini=2*mini-s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.top()>mini)
            return s.top();
        return mini;
        
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */