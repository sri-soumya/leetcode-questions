class Solution {
public:
    
    int check(vector<vector<int>>& matrix, vector<int> &a)
    {
        map<int,int> mp;
        for(auto x:a)
            mp[x]++;
        
        int c=0;
        
        for(int i=0;i<matrix.size();i++)
        {
            bool f=true;
            
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                    continue;
                if(!mp.count(j))
                {
                    f=false;
                    break;
                }
            }
            
            c+=f;
        }
        
        return c;
    }
    
    void solve(vector<vector<int>>& matrix, vector<int> &a,int i,int &ans,int p)
    {
        if(i==a.size())
        {
            int x=check(matrix,a);
            //cout<<a[0]<<a[1]<<x<<endl;
            ans=max(ans,x);
            return;
        }
        
        for(int j=p+1;j<matrix[0].size();j++)
        {
            a[i]=j;
            solve(matrix,a,i+1,ans,j);
            a[i]=-1;
        }
    }
    
    int maximumRows(vector<vector<int>>& matrix, int m) {
        
        vector<int> a(m,-1);
        int ma=0;
        solve(matrix,a,0,ma,-1);
        
        return ma;
    }
};