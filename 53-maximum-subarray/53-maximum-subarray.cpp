class Solution {
public:
    int maxSubArray(vector<int>& a) {
        
        int s=0,ans=INT_MIN,n=a.size();
        
        for(int i=0;i<n;i++)
        {
            s+=a[i];
            ans=max(ans,s);
            s=max(s,0);
        }
        return ans;
    }
};