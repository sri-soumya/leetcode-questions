class LUPrefix {
public:
    set<int> a;
    LUPrefix(int n) {
        for(int i=1;i<=n;i++)
        {
            a.insert(i);
        }
        a.insert(n+1);
    }
    
    void upload(int video) {
        a.erase(video);
    }
    
    int longest() {
        return *a.begin()-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */