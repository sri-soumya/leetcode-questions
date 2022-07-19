class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==0)
                    continue;
                int l=1e8,t=1e8;
                if(j-1>=0)
                    l=a[i][j-1];
                if(i-1>=0)
                    t=a[i-1][j];
                a[i][j]=1+min(l,t);
            }
        }
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]==0)
                    continue;
                int r=1e8,b=1e8;
                if(j+1<n)
                    r=a[i][j+1];
                if(i+1<m)
                    b=a[i+1][j];
                a[i][j]=min(a[i][j],1+min(r,b));
            }
        }
        
        return a;
    }
};