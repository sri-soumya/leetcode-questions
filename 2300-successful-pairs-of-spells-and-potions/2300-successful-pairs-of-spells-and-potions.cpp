class Solution {
public:
    vector<int> successfulPairs(vector<int>& v, vector<int>& b, long long s) {
        int n=v.size(),m=b.size();
        vector<pair<int,int>> a;
        
        for(int i=0;i<n;i++)
        {
            a.push_back({v[i],i});    
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        vector<int> c(n,0);
        for(int i=0;i<n;i++)
        {
            int z=0;
            if(i>0)
                z=c[a[i-1].second];
            int x=0;
            for(int j=z;j<m;j++)
            {
                long long p=a[i].first;
                p*=b[j];
                if(p>=s)
                    x++;
                else
                    break;
            }
            
            c[a[i].second]=x+z;
        }
        
        return c;
    }
};