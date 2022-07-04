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
            //cout<<p[i]<<" ";
        }
        
        
        
        int s=0;
        //cout<<endl;
        for(int i=n-2;i>=1;i--)
        {
            if(a[i]>a[i+1]&&p[i]<=p[i+1])
                p[i]=p[i+1]+1;
            //cout<<p[i]<<" ";
            s+=p[i];
        }
        
        // for(int i=1;i<n-1;i++)
        //     cout<<p[i]<<" ";
        // cout<<endl;
        return s;
        
    }
};