class StockSpanner {
public:
    stack<pair<int,int>> s;
    vector<int> a;
    int c;
    StockSpanner() {
        c=-1;
    }
    
    int next(int price) {
        c++;
        while(s.size()&&price>=s.top().first)
        {
            s.pop();
        }
        int ans;
        if(s.size())
            ans=c-s.top().second;
        else
            ans=c+1;
        s.push({price,c});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */