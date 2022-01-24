class Solution {
public:
    
    int solve(vector<int> nums)
    {
        if(nums.size()==0)
            return INT_MAX;
        if(nums.size()==1)
            return nums[0];
        
        int n=nums.size();
        int m=(n-1)/2;
        
        vector<int> l(nums.begin(),nums.begin()+m);
        vector<int> r(nums.begin()+m+1,nums.end());
        int ll=solve(l);
        int rr=solve(r);
        
        cout<<m<<" "<<ll<<" "<<nums[m]<<" "<<rr<<endl;
        return min(nums[m],min(ll,rr));
        //return min(nums[m],min(solve(l),solve(r)));
    }
    
    int findMin(vector<int>& nums) {
       return solve(nums);
    }
};