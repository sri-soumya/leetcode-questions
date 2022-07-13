class Solution {
public:
    
    void dfs(vector<vector<int>> &a,vector<int> &v,int i)
    {
        v[i]=1;
        int n=a.size();
        for(int j=0;j<n;j++)
        {
            if(a[i][j]&&!v[j])
                dfs(a,v,j);
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& a) {
        
        int n=a.size(),c=0;
        vector<int> v(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!v[i])
            {
                dfs(a,v,i);
                c++;
            }
        }
        
        return c;
    }
};