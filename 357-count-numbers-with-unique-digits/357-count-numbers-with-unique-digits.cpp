class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        //vector<int> dp(n+1,0);
        //dp[0]=1;
        int s=10,c=1,x=1;
        for(int i=1;i<=n;i++)
        {
            
            //dp[i]=s;
            x=s;
            s+=(x-c)*(10-i);
            c=x;
            
        }
        return x;        
    }
};