class Solution {
public:
    
    bool dfs(vector<vector<char>>& a, string b,vector<vector<bool>> &v,int i,int j,int k)
    {
        int m=a.size(),n=a[0].size();
        int l=b.length();
         if(k==l)
            return true;
        if(i<0||j<0||i>=m||j>=n||v[i][j])
            return false;
       
        if(a[i][j]!=b[k])
            return false;
        
        //cout<<i<<" "<<j<<" "<<k<<endl;
        
        
        v[i][j]=true;
        
        bool f=dfs(a,b,v,i+1,j,k+1)||dfs(a,b,v,i-1,j,k+1)||dfs(a,b,v,i,j+1,k+1)||dfs(a,b,v,i,j-1,k+1);
        v[i][j]=false;
        
        return f;
    }
    
    bool exist(vector<vector<char>>& a, string b) {
        
        int m=a.size(),n=a[0].size();
        int l=b.length();
        vector<vector<bool>> v(m,vector<bool>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==b[0]&&dfs(a,b,v,i,j,0))
                    return true;
            }
        }
        
        return false;
        
    }
};