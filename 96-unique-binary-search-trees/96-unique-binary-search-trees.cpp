class Solution {
public:
    
    int solve(int n)
    {
        if(n<=2)
            return max(0,n);
        
        int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            ans+=max(1,solve(i-1))*max(1,solve(n-i));
        }
        
        return ans;
    }
    
    int numTrees(int n) {
        
        return solve(n);
    }
};