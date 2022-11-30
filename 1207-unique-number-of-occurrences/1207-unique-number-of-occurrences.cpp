class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m1,m2;
        
        for(auto x:arr)
            m1[x]++;
        
        for(auto x:m1)
        {
            if(m2.count(x.second))
                return 0;
            m2[x.second]++;
        }
        
        return 1;
    }
};