class Solution {
public:
    
    bool check(vector<int> &a)
    {
        for(int i=0;i<32;i++)
        {
            if(a[i]>=2)
                return false;
        }
        
        return true;
    }
    
    void add(vector<int> &a,int x)
    {
        int c=0;
        while(x)
        {
            if(x&1)
                a[31-c]++;
            x/=2;
            c++;
        }
    }
    
    void sub(vector<int> &a,int x)
    {
        int c=0;
        while(x)
        {
            if(x&1)
                a[31-c]--;
            x/=2;
            c++;
        }
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int j=0,c=0,ans=0;
        vector<int> a(32,0);
        for(int i=0;i<n&&j<n;i++)
        {
            j=max(i,j);
            while(j<n)
            {
                add(a,nums[j]);
                if(!check(a))
                {
                    sub(a,nums[j]);
                    break;
                }
                j++;
            }
            
            ans=max(ans,j-i);
            
            sub(a,nums[i]);
            
        }
        
        return ans;
        
    }
};