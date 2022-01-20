class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int> a(n);
        
        a[n-1]=-1;
        
        
        for(int i=n-2;i>=0;i--)
        {
            a[i]=max(a[i+1],prices[i+1]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,a[i]-prices[i]);
        }
        
        return ans;
        
    }
};