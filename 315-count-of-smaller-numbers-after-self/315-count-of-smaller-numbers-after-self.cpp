#define ff first
#define ss second
class Solution {
public:
    
    void solve(vector<pair<int,int>> &a,int s,int e,vector<int> &ans)
    {
        
        if(s>=e)
            return;
        
        int m=(s+e)/2;
        int i1=s,j1=m,i2=m+1,j2=e;
        solve(a,i1,j1,ans);
        solve(a,i2,j2,ans);
        
        vector<pair<int,int>> temp(e-s+1);
        int c=0,less=0;
        
        while(i1<=j1&&i2<=j2)
        {
            if(a[i2].ff<a[i1].ff)
            {
                less++;
                temp[c++]=a[i2++];
            }
            
            else
            {
                ans[a[i1].ss]+=less;
                temp[c++]=a[i1++];
            }
        }
        
        while(i1<=j1)
        {
            ans[a[i1].ss]+=less;
            temp[c++]=a[i1++];
        }
        
        while(i2<=j2)
        {
            temp[c++]=a[i2++];
        }
       
        for(int x=0;x<e-s+1;x++)
        {
            a[s+x]=temp[x];
        }
        
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> a(n);
        
        for(int i=0;i<n;i++)
        {
            a[i]={nums[i],i};
        }
        
        solve(a,0,n-1,ans);
        
        return ans;
    }
};