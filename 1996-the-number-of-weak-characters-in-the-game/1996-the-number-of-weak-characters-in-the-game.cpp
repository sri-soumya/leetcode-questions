class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]>b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        
        sort(a.begin(),a.end(),cmp);
        int n=a.size(),c=0,m=0;
        
        for(auto x:a)
        {
            if(x[1]<m)
                c++;
            m=max(m,x[1]);
        }
        
        return c;
    }
};