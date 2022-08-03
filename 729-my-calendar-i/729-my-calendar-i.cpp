#define pii pair<int,int>
#define ff first
#define ss second
class MyCalendar {
public:
    vector<pii> a;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(end>a[i].ff&&start<a[i].ss)
                return false;
            
        }
        
        a.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */