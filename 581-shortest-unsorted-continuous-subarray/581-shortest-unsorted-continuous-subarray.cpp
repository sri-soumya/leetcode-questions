class Solution {
public:
    
    bool solve(vector<int> a,int i)
    {
        int n=a.size();
        if(n<=1)
            return false;
        if(i==0)
            return a[i]>a[i+1];
        if(i==n-1)
            return a[i]<a[i-1];
        
        return a[i]>a[i+1]||a[i]<a[i-1];
        return false;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
     
        int s=INT_MAX,l=INT_MIN,n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(solve(nums,i))
            {
                s=min(nums[i],s);
                l=max(nums[i],l);
            }
        }
        
        if(s==INT_MAX)
            return 0;
        
        int ll=0;
        int r=n-1;
        
        while(ll<n&&nums[ll]<=s)
        {
            ll++;
        }
        
        while(r>=0&&nums[r]>=l)
        {
            r--;
        }
        
        
        return r-ll+1;
        
    }
};