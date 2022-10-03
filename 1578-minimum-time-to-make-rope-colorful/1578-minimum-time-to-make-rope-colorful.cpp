class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0,m=neededTime[0],sum=neededTime[0];
        
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            {
                sum+=neededTime[i];
                m=max(m,neededTime[i]);
            }
            else
            {
                ans+=sum-m;
                sum=neededTime[i];
                m=neededTime[i];
            }
        }
        
        return ans+sum-m;
    }
};