class Solution {
public:
    
    bool check(string s,int in,int n,int** dp)
    {
        int x=in,y=n;
        while(in<n)
        {
            if(dp[in][n]!=-1)
                return dp[x][y]=dp[in][n];
            if(s[in]!=s[n])
                return dp[x][y]= false;
            in++;n--;
        }
        
        return dp[x][y]=true;
    }
    
    int solve(string s,int in,int **dp)
    {
        int n=s.length();
        
        int i,maxi=i;
        for(i=in;i<n;i++)
        {
            if(check(s,in,i,dp))
                maxi=i;
        }
        //cout<<s[in]<<" "<<maxi<<endl;
        return maxi;
    }
    
    string longestPalindrome(string s) {
        
        
        int c=0,n=s.length();string ans="";
        bool** dp=new bool*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new bool[n];
            for(int j=0;j<n;j++)
                dp[i][j]=false;
            
            dp[i][i]=1;
            if(i+1<n)
                dp[i][i+1]=s[i]==s[i+1];
            
        }
        
        int x=0,y=0;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                dp[i][j]=dp[i+1][j-1]&&s[i]==s[j];
            }
        }
        
        int max=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(dp[i][j]&&j-i+1>max)
                {
                    x=i;
                    y=j;
                    max=j-i+1;
                }
            }
        }
        
        
        return s.substr(x,y-x+1);
        
    }
};