class Solution {
public:
    
    static bool compare(string a,string b)
    {
        return a.length()<b.length();
    }
    
    int solve(vector<string> &a,int i,int j,vector<vector<int>> &dp)
    {
        int n=a.size();
        if(i==n)
            return 0;
        
        if(j!=-1&&dp[i][j]!=-1)
            return dp[i][j];
        
        int c1=0,c2=0;
        c1=solve(a,i+1,j,dp);
        bool f=true;
        int y=0,x;
        if(j==-1)
            c2=solve(a,i+1,i,dp)+1;
        else
        {
            int nn=a[j].length(),mm=a[i].length();
            int x=0,y=0;
            bool f=true;
            while(x<nn&&y<mm)
            {
                if(a[j][x]==a[i][y])
                {
                    x++;
                    y++;
                }
                else
                    y++;
            }
            
            if(x<nn&&y>=mm)
                f=false;
            
            if(f&&((mm-nn)==1))
                c2=1+solve(a,i+1,i,dp);
            
            dp[i][j]= max(c1,c2);
        }
        
        
        return max(c1,c2);
        
        
    }
    
    int longestStrChain(vector<string>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),compare);
        // for(int i=0;i<n;i++)
        //     cout<<a[i]<<" ";
        // cout<<endl;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(a,0,-1,dp);
    }
};