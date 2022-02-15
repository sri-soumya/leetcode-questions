class StockSpanner {
public:
    stack<pair<int,int>> s;
    vector<int> a;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int res=1;
        while(s.size()&&price>=s.top().first)
        {
            res+=s.top().second;
            s.pop();
            
        }
        
        s.push({price,res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */