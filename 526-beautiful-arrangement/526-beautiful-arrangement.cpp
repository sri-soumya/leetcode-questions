class Solution {
public:
    
    bool check(vector<int> &a,int in,int x)
    {
        while(in>=0)
        {
            if(a[in]==x)
                return false;
            in--;
        }
        
        return true;
    }
    
    
    int solve(vector<int> &a,int in)
    {
        int n=a.size();
        if(in==n)
        {
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i%(in+1)==0&&check(a,in-1,i))
            {
                a[in]=i;
                ans+=solve(a,in+1);
                a[in]=0;
            }
            else if((in+1)%i==0&&check(a,in-1,i))
            {
                a[in]=i;
                ans+=solve(a,in+1);
            }
        }
        
        return ans;
    }
    
    int countArrangement(int n) {
        vector<int> a(n);
        
        return solve(a,0);
    }
};