class Solution {
public:
    
    bool check(vector<vector<int>> &a,int i,int j)
    {
        int n=a.size(),m=a[0].size();
        vector<int> dy={-1,0,0,1};
        vector<int> dx={0,-1,1,0};
        
        for(int k=0;k<4;k++)
        {
            int ni=i+dy[k],nj=j+dx[k];
            
            if(ni<0||nj<0||ni>=n||nj>=m||(a[ni][nj]!=a[i][j]&&a[ni][nj]>0))
                return true;
        }
        
        return false;
    }
    
    void solve(vector<vector<int>>& a, int i, int j, int t)
    {
        int n=a.size(),m=a[0].size();
        
        if(a[i][j]<0)
            return;
        
        int pc=a[i][j];
        if(check(a,i,j))
        {
            //cout<<i<<" "<<j<<endl; 
            a[i][j]=t;
        }
        
        a[i][j]*=-1;
        
        vector<int> dy={-1,0,0,1};
        vector<int> dx={0,-1,1,0};
        
        for(int k=0;k<4;k++)
        {
            int ni=i+dy[k],nj=j+dx[k];
            
            if(ni<0||nj<0||ni>=n||nj>=m||a[ni][nj]!=pc)
                continue;
            solve(a,ni,nj,t);
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& a, int row, int col, int t) {
        
        solve(a,row,col,t);
        
        int n=a.size(),m=a[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                a[i][j]=abs(a[i][j]);
        }
        
        return a;
    }
};