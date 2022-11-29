class RandomizedSet {
public:
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val))
            return false;
        mp[val]++;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val))
            return false;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=mp.size();
        int in=rand()%n;
        auto it=mp.begin();
        advance(it,in);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */