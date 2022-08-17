class Solution {
public:
    
    bool solve(vector<int> &stones,int in,int k,map<pair<int,int>,int> &dp)
    {
        int n=stones.size();
        
        if(in==n-1)
            return 1;
        
        if(dp.count({in,k}))
            return dp[{in,k}];
        
        bool ans=false;
        
        for(int i=in+1;i<n;i++)
        {
           
            if(stones[in]+k!=stones[i])
                continue;
            if(solve(stones,i,k-1,dp)||solve(stones,i,k,dp)||solve(stones,i,k+1,dp))
                return true;
            
        }
        
        return dp[{in,k}]= false;
    }
    
    bool canCross(vector<int>& stones) {
        
        int n=stones.size();
        if(stones[0]-stones[1]!=-1)
            return false;
        map<pair<int,int>,int> dp;
        return solve(stones,0,1,dp);
    }
};