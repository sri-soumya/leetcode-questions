
class MinStack {
public:
    stack<pair<int,int>> s;
    int mini;
    MinStack() {
        //s=new vector<int>;
        mini=INT_MAX;
    }
    
    void push(int val) {
        int c=(s.size())?s.top().second:INT_MAX;
        s.push({val,min(val,c)});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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