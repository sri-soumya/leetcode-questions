class MedianFinder {
    
    priority_queue<int> f;
    priority_queue<int,vector<int>,greater<int>> s;
    
public:
    
    MedianFinder() {
        
    }
    
    void addNum(int x) {
        
        
        if(!f.size()||f.top()>x)
            f.push(x);
        else
            s.push(x);
        while(f.size()>1+s.size())
        {
            s.push(f.top());
            f.pop();
        }
        
        while(f.size()<s.size())
        {
            f.push(s.top());
            s.pop();
        }
        
    }
    
    double findMedian() {
        
        if(f.size()!=s.size())
            return f.top();
        
        return (f.top()+s.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */