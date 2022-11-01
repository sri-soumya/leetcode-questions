class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& grid)
    {
        int m=grid.size(),n=grid[0].size();
        // if(j<0||j>=n)
        //     return -1;
        
        if(i==m)
            return j;
        //cout<<i<<" "<<j<<endl;
        if(grid[i][j]==1&&(j+1<n&&grid[i][j+1]==1))
            return solve(i+1,j+1,grid);
        
        if(grid[i][j]==-1&&(j-1>=0&&grid[i][j-1]==-1))
            return solve(i+1,j-1,grid);
        
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            ans[i]=solve(0,i,grid);
            //cout<<endl;
        }
        
        return ans;
        
    }
};