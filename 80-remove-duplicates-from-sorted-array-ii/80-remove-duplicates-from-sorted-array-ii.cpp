class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int nn=0,c=nums[0],k=1,s=0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==c)
            {
                k++;
                // if(k>2)
                //     s++;
                nums[i-s]=nums[i];
            }
            else
            {
                c=nums[i];
                if(k>2)
                    s+=k-2;
                k=1;
                nums[i-s]=nums[i];
            }
        }
        
        if(k>2)
            s+=k-2;
        
        return n-s;
    }
};