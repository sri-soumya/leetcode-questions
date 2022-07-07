class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        
        int n=a.size();
        vector<int> dp;
        
        for(int i=0;i<n;i++)
        {
            int in=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
            if(in==dp.size())
                dp.push_back(a[i]);
            else
            {
                //if(dp[in]>a[i])
                    dp[in]=a[i];
            }
            if(dp.size()==3)
                return true;
                
        }
       
        return false;
    }
};