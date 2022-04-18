class MedianFinder {
public:
    
    priority_queue<int> f;
    priority_queue<int,vector<int>,greater<int>> s;
    int c=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!c)
            f.push(num);
        else
        {
            if(num<f.top())
                f.push(num);
            else
                s.push(num);
        }
        c++;
        while(f.size()>1+s.size())
        {
            s.push(f.top());
            f.pop();
        }
        while(s.size()>1+f.size())
        {
            f.push(s.top());
            s.pop();
        }
    }
    
    double findMedian() {
        if(c==1)
            return f.top();
        if(f.size()>s.size())
            return f.top();
        if(s.size()>f.size())
            return s.top();
        return (f.top()+s.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */