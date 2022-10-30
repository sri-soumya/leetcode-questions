class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        queue<vector<int>> q;
        q.push({0,0,k,0});
        vector<vector<int>> b(n,vector<int>(m,-1));
        int c=0;
        while(q.size())
        {
            int l=q.size();
            vector<int> a=q.front();
            q.pop();
                
            if(a[0]<0||a[1]<0||a[0]>=n||a[1]>=m||(grid[a[0]][a[1]]==1&&a[2]<=0))
                continue;
            if(grid[a[0]][a[1]]==1)
                a[2]--;
            if(a[0]==n-1&&a[1]==m-1)
                return a[3];
            if(b[a[0]][a[1]]!=-1&&b[a[0]][a[1]]>=a[2])
                continue;
            b[a[0]][a[1]]=a[2];
                
            a[3]++;
            q.push({a[0]+1,a[1],a[2],a[3]});
            q.push({a[0]-1,a[1],a[2],a[3]});
            q.push({a[0],a[1]-1,a[2],a[3]});
            q.push({a[0],a[1]+1,a[2],a[3]});
            
        }
        
        return -1;
    }
};