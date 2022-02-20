class Solution {
public:
    
    int lb(vector<int> a,int t)
    {
        int n=a.size();
        int l=0,u=n-1;
        while(l<=u)
        {
            int m=(l+u)/2;
            if(t<=a[m])
                u=m-1;
            else
                l=m+1;
        }
        
        return l;
    }
    
    int ub(vector<int> a,int t)
    {
        int n=a.size();
        int l=0,u=n-1;
        while(l<=u)
        {
            int m=(l+u)/2;
            if(t<a[m])
                u=m-1;
            else
                l=m+1;
        }
        
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=lb(nums,target);
        int b=ub(nums,target);
        
        //int a=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        //int b=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(a==nums.size()||target!=nums[a])
            return {-1,-1};
        return {a,b-1};
        
    }
};