class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> x;
        int s=0;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            if(s==k)
                c++;
            else if(x.count(s-k));
                c+=x[s-k];
            x[s]++;
        }
        
        return c;
    }
};