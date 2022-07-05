class Solution {
public:
    
    bool dfs(vector<vector<char>>& a, string b,int i,int j,int k)
    {
        int m=a.size(),n=a[0].size();
        int l=b.length();
         if(k==l)
            return true;
        if(i<0||j<0||i>=m||j>=n||a[i][j]=='#')
            return false;
       
        if(a[i][j]!=b[k])
            return false;
        
        char c=a[i][j];
        a[i][j]='#';
        bool f=dfs(a,b,i+1,j,k+1)||dfs(a,b,i-1,j,k+1)||dfs(a,b,i,j+1,k+1)||dfs(a,b,i,j-1,k+1);
        a[i][j]=c;
        return f;
    }
    
    bool exist(vector<vector<char>>& a, string b) {
        
        int m=a.size(),n=a[0].size();
        int l=b.length();
        //vector<vector<bool>> v(m,vector<bool>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==b[0]&&dfs(a,b,i,j,0))
                    return true;
            }
        }
        
        return false;
        
    }
};