class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> f(n,1),w(n,1);
	    int m=1,in=0;
        for(int i=1;i<n;i++)
        {
            int c=0;
            for(int j=0;j<i;j++)
            {
                if(a[j]<a[i]&&f[j]+1>f[i])
                {
                    f[i]=f[j]+1;
                    w[i]=w[j];
                }
                else if(a[j]<a[i]&&f[j]+1==f[i])
                    w[i]+=w[j];
            }

            //f[i]+=c;
            m=max(m,f[i]);
        }
        int ans=0;
        // for(int i=0;i<n;i++)
        //     cout<<f[i]<<" ";
            
        //cout<<endl;
//         for(int i=0;i<n;i++)
//         {
//             int c=0;
//             for(int j=i-1;j>=0;j--)
//             {
//                 if(f[j]==f[i]-1&&a[j]<a[i])
//                     c+=w[j];
//             }
            
//             w[i]=max(w[i],c);
//             if(f[i]==m)
//                 ans+=w[i];
//         }
        
        for(int i=0;i<n;i++)
            if(f[i]==m)
                ans+=w[i];
        //     cout<<w[i]<<" ";
        return ans;
    }
};