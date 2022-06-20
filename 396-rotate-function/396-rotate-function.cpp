class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        
        int s=0,p=0,m=0,n=a.size();
        
        for(int i=0;i<n;i++)
        {
            s+=a[i];
            p+=i*a[i];
        }
        //cout<<p<<endl;
        m=p;
        
        for(int i=1;i<n;i++)
        {
            int b=p-(a[n-i]*(n-1))+s-a[n-i];
            p=b;
            m=max(m,p);
        }
        
        return m;
    }
};