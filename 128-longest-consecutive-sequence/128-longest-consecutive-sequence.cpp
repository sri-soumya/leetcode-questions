class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,bool> x;
        int n=nums.size();
        for(int i=0;i<n;i++)
            x[nums[i]]=true;
        
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            int l=nums[i];
            if(x.count(nums[i]-1))
                continue;
            int v=1;
            // for(;;l--)
            // {
            //     if(x.count(l)&&x[l])
            //     {
            //         v++;
            //         x[l]=false;
            //     }
            //     else
            //         break;
            // }
            
            for(l=nums[i]+1;;l++)
            {
                if(x.count(l)&&x[l])
                {    
                    v++;
                    x[l]=false;
                }
                else
                    break;
            }
            
            c=max(c,v);
        }
        
        return c;
        
    }
};