class Solution {
public:
    
    void dfs(vector<vector<int>>& heights,vector<vector<pair<int,int>>> &e,int i,int j,int p,int f)
    {
        int m=heights.size(),n=heights[0].size();
        if(i<0||j<0||i>=m||j>=n||heights[i][j]<p||(!f&&e[i][j].first)||(f&&e[i][j].second))
            return;
        
        if(!f)
            e[i][j].first++;
        else
            e[i][j].second++;
        
        dfs(heights,e,i+1,j,heights[i][j],f);
        dfs(heights,e,i-1,j,heights[i][j],f);
        dfs(heights,e,i,j+1,heights[i][j],f);
        dfs(heights,e,i,j-1,heights[i][j],f);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m=heights.size(),n=heights[0].size();
        vector<vector<pair<int,int>>> e(m,vector<pair<int,int>>(n,{0,0}));
        
        for(int i=0;i<n;i++)
        {
            dfs(heights,e,0,i,heights[0][i],0);
            dfs(heights,e,m-1,i,heights[m-1][i],1);
        }
        
        for(int i=0;i<m;i++)
        {
            dfs(heights,e,i,0,heights[i][0],0);
            dfs(heights,e,i,n-1,heights[i][n-1],1);
        }
        
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(e[i][j].first&&e[i][j].second)
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};