class Solution {
public:
    
    int solve(vector<int> &nums,int in,int n)
    {
        if(in>=n)
            return 0;
        
        int m=(n-in)/2;
        int fe=in+m;
        int ss=fe+1;
        
        vector<int> a(nums.begin()+in,nums.begin()+fe+1);
        vector<int> b(nums.begin()+ss,nums.begin()+n+1);
        

        
        //int l=0,r=0;
        
        int l=solve(a,0,a.size()-1);
        int r=solve(b,0,b.size()-1);
        int x=0;
        
//                 for(int i=in;i<a.size();i++)
//             cout<<a[i]<<" ";
//         cout<<endl;
        
//         for(int i=in;i<b.size();i++)
//             cout<<b[i]<<" ";
//         cout<<endl;
        int j=0;
        for(int i=0;i<a.size();i++)
        {
            //int j=0;
            while(j<b.size()&&a[i]/2.0>b[j])
            {
                j++;
            }
            x+=j;
        }
        
        //cout<<x<<endl<<endl;
        
        int i=0,c=0;
        j=0;
        while(i<a.size()&&j<b.size())
        {
            
            // if(a[i]>2*b[j])
            //         x+=a.size()-1-i;
            
            if(a[i]<=b[j])
                nums[c++]=a[i++];
            else
            {
                // if(a[i]>2*b[j])
                //     x+=a.size()-1+i;
                nums[c++]=b[j++];
            }
        }
        
        while(i<a.size())
        {
            nums[c++]=a[i++];
        }
        
        while(j<b.size())
        {
            nums[c++]=b[j++];
        }
        
        // for(int i=in;i<=n;i++)
        //     cout<<nums[i]<<" ";
        // cout<<endl;
        
        return l+r+x;
        
        
    }
    
    int reversePairs(vector<int>& nums) {
     
        return solve(nums,0,nums.size()-1);
        
    }
};