class Solution {
public:
    
    void print(vector<int> cols)
    {
        for(int i=0;i<cols.size();i++)
            cout<<cols[i]<<" ";
        cout<<endl;
    }
    
    bool isvalid(int in,int r,vector<int> cols)
    {
        for(int i=0;i<r;i++)
        {
            if(cols[i]==in||(abs(i-r)==abs(cols[i]-in)))
                return false;
                
        }
        
        if(r>0&&(cols[r-1]==in-1||cols[r-1]==in+1))
            return false;
        
        return true;
    }
    
    void solve(int in,int n,vector<vector<string>>& a,vector<string>& b, vector<int>& cols,string s)
    {
        if(in>=n)
        {
            if(b.size()==n)
            a.push_back(b);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            
            if(isvalid(i,in,cols))
            {
                cols[in]=i;
                s[i]='Q';
                b.push_back(s);
                s[i]='.';
                solve(in+1,n,a,b,cols,s);
                  
                cols[in]=-1;
                b.pop_back();
                
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> a;
        string s="";
        for(int i=0;i<n;i++)
        {
            s+=".";
            //a[i]=vector<string>(n,".");
        }
               
        vector<string> b;
        vector<int> cols(n,-1);
        solve(0,n,a,b,cols,s);
        return a;
    }
};