class Solution {
public:
    int candy(vector<int>& a) {
        
        a.insert(a.begin(),INT_MAX);
        a.push_back(INT_MAX);
        
        int n=a.size();
        vector<int> p(n,1);
        
        for(int i=1;i<n-1;i++)
        {
            
            if(a[i]>a[i-1])
                p[i]=p[i-1]+1;
        }
        
        
        
        int s=0;
        for(int i=n-2;i>=1;i--)
        {
            if(a[i]>a[i+1]&&p[i]<=p[i+1])
                p[i]=p[i+1]+1;
            s+=p[i];
        }

        return s;
        
    }
};