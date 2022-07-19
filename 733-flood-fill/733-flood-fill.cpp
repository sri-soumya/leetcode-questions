class Solution {
public:
    
    void solve(vector<vector<int>>& a, int i, int j, int t)
    {
        int n=a.size(),m=a[0].size();
        
        if(a[i][j]==t)
            return;
        int pc=a[i][j];
        a[i][j]=t;
        
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
    
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int t) {
        
        vector<vector<int>> b=a;
        
        solve(b,sr,sc,t);
        return b;
    }
};