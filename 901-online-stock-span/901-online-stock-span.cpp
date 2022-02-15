class StockSpanner {
public:
    stack<int> s;
    vector<int> a;
    StockSpanner() {
        
    }
    
    int next(int price) {
        a.push_back(price);
        int i=a.size()-1;
        while(s.size()&&a[i]>=a[s.top()])
            s.pop();
        int ans;
        if(!s.size())
            ans=i+1;
        else
            ans=i-s.top();
        s.push(i);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */