class Solution {
public:
    int majorityElement(vector<int>& nums) {
     
        //moor's voting algorithm
        int n=nums.size();
        int c=0;
        int e=0;
        for(int i=0;i<n;i++)
        {
            if(c==0)
                e=nums[i];
            if(e==nums[i])
                c++;
            else
                c--;
            
        }
        
        return e;
        
    }
};