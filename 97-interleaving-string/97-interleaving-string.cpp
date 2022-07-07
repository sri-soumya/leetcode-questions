class Solution {
public:
    
    bool solve(string s1,string s2,string s3,int i,int j,int k,vector<vector<vector<int>>> &dp)
    {
        if(i==-1&&j==-1&&k==-1)
            return true;
        
        if(i>=0&&j>=0&&k>=0&&dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        bool f1=0,f2=0;
        if(i>=0&&k>=0&&s1[i]==s3[k])
            f1=solve(s1,s2,s3,i-1,j,k-1,dp);
        if(j>=0&&k>=0&&s2[j]==s3[k])
            f2=solve(s1,s2,s3,i,j-1,k-1,dp);
        
        if(i>=0&&j>=0&&k>=0)
            dp[i][j][k]=f1||f2;
        
        return  f1||f2;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.length(),m=s2.length(),k=s3.length();
        
//         while(k>=0)
//         {
//             cout<<n<<" "<<m<<" "<<k<<endl;
//             if(n>=0&&s1[n]==s3[k])
//             {
//                 n--;
//                 k--;
//             }
//             else if(m>=0&&s2[m]==s3[k])
//             {
//                 m--;
//                 k--;
//             }
//             else
//                 break;
//         }
        
//         return n==-1&&m==-1&&k==-1;
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1))); 
        //vector<int> dp(k,-1);
        return solve(s1,s2,s3,n-1,m-1,k-1,dp);
        
     }
};