class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size(),t=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j])
                    t++;
            }
        }
        
        int c=0;
        int z=0;
        
        while(q.size())
        {
            int l=q.size();
            c+=l;
            while(l)
            {
                l--;
                int r=q.front().first,c=q.front().second;
                q.pop();
                if(r-1>=0&&grid[r-1][c]==1)
                {
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                }
                if(r+1<n&&grid[r+1][c]==1)
                {
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                }
                if(c-1>=0&&grid[r][c-1]==1)
                {
                    grid[r][c-1]=2;
                    q.push({r,c-1});
                }
                if(c+1<m&&grid[r][c+1]==1)
                {
                    grid[r][c+1]=2;
                    q.push({r,c+1});
                }
            }
            if(q.size())
                z++;
        }
        
        if(c==t)
            return z;
        return -1;
    }
};