class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> x;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            x[nums[i]]++;
        
        int m=0;
        
        for(int i=0;i<n;i++)
        {
            if(x.count(nums[i]-1))
                continue;
            
            int c=0;
            int z=nums[i];
            
            while(x.count(z))
            {
                c++;
                z++;
            }
            
            m=max(m,c);
        }
        
        return m;
        
        
    }
};