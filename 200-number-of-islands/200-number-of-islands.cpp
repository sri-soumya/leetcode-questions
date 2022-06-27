class Solution {
public:
    
    void dfs(vector<vector<char>> &a,int i,int j)
    {
        int n=a.size(),m=a[0].size();
        
        a[i][j]='0';
        int dy[4]={-1,0,0,1};
        int dx[4]={0,-1,1,0};
        
        for(int x=0;x<4;x++)
        {
            if(i+dy[x]<0||i+dy[x]>=n||j+dx[x]<0||j+dx[x]>=m||a[i+dy[x]][j+dx[x]]=='0')
                continue;
            dfs(a,i+dy[x],j+dx[x]);
        }
    }
    
    
    int numIslands(vector<vector<char>>& a) {
        
        int n=a.size(),m=a[0].size(),c=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='0')
                    continue;
                c++;
                dfs(a,i,j);
            }
        }
        
        return c;
    }
};