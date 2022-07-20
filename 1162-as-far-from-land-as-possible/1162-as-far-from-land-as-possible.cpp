class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    a[i][j]=0;
                    continue;
                }
                
                int t=1e8,l=1e8;
                if(i-1>=0)
                    t=a[i-1][j];
                if(j-1>=0)
                    l=a[i][j-1];
                a[i][j]=min(l,t)+1;
            }
        }
        
        int ans=0;
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int b=1e8,r=1e8;
                if(i+1<m)
                    b=a[i+1][j];
                if(j+1<n)
                    r=a[i][j+1];
                a[i][j]=min(a[i][j],1+min(b,r));
                ans=max(ans,a[i][j]);
            }    
            
        }
        
        if(ans>=1e8||ans==0)
            return -1;
        return ans;
        
    }
};