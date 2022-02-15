
class MinStack {
public:
    vector<int> s;
    int mini;
    MinStack() {
        //s=new vector<int>;
        mini=INT_MAX;
    }
    
    void push(int val) {
        mini=min(mini,val);
        s.push_back(val);
    }
    
    void pop() {
        int x=top();
        s.pop_back();
        if(x!=mini)
            return;
        mini=INT_MAX;
        for(int i=0;i<s.size();i++)
            mini=min(mini,s[i]);
    }
    
    int top() {
        return s[s.size()-1];
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