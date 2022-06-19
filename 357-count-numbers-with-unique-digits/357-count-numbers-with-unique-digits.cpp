class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            int s=0,c=0;
            //int k=10;
            
            for(int j=0;j<i;j++)
            {
               
                s+=(dp[j]-c)*(10-j);
                 c=dp[j];
            }
            
            dp[i]=s;
        }
        return dp[n];        
    }
};